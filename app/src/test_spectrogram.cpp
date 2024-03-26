#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"

int getHammingWindow(int len, float32_t *window) {
    if (len <= 0 || window == NULL) {
        return -1; // Invalid input parameters
    }

    for (int i = 0; i < len; i++) {
        window[i] = 0.54f - 0.46f * cos(2 * M_PI * i / (len - 1));
    }

    return 0; // Success
}

// Function to compute spectrogram
int compute_spectrogram(float32_t *signal, int signalLen, int segmentLen, int overlap, float32_t *outputSpectrogram[]) {
    // Calculate the number of segments
    int numSegments = (signalLen - segmentLen) / overlap + 1;

    // Allocate memory for the spectrogram
    for (int i = 0; i < segmentLen / 2 + 1; i++) {
        outputSpectrogram[i] = (float32_t *)malloc(numSegments * sizeof(float32_t));
        if (outputSpectrogram[i] == NULL) {
            // Free memory allocated so far
            for (int j = 0; j < i; j++) {
                free(outputSpectrogram[j]);
            }
            return -1; // Memory allocation failed
        }
    }

    float32_t hammingWindow[segmentLen];
    getHammingWindow(segmentLen, hammingWindow);
    print_array(hammingWindow, segmentLen);

    // Compute spectrogram
    for (int i = 0; i < signalLen - segmentLen; i += overlap) {
        // Extract segment
        float32_t segment[segmentLen];
        for (int j = 0; j < segmentLen; j++) {
            segment[j] = signal[i + j];
        }

        // Apply windowing function
        float32_t windowedSegment[segmentLen];
        arm_mult_f32(segment, hammingWindow, windowedSegment, segmentLen);

        // Compute FFT
        arm_rfft_fast_instance_f32 fftInstance;
        arm_rfft_fast_init_f32(&fftInstance, segmentLen);
        arm_rfft_fast_f32(&fftInstance, windowedSegment, outputSpectrogram[i / overlap], 0);
    }

    return numSegments;
}

