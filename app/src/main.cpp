#include <stdio.h>
#include <dsp/basic_math_functions.h>
#include "dsp.h"

void test_spectogram(){

	// Example parameters
    int signalLen = 1024; // Length of the input signal
    int segmentLen = 256; // Length of each segment
    int overlap = 128; // Overlap between segments

    // Allocate memory for the input signal (example)
    float32_t *signal = (float32_t *)malloc(signalLen * sizeof(float32_t));
    
    // Initialize or fill the input signal with your data
	for (int i = 0; i < signalLen; i++){
		*(signal + i) = *(input_15K_to_1K_50kHz + i);
	}

    // Allocate memory for the spectrogram
    float32_t **outputSpectrogram = (float32_t **)malloc((segmentLen / 2 + 1) * sizeof(float32_t *));

    // Call the compute_spectrogram function
    int numSegments = compute_spectrogram(signal, signalLen, segmentLen, overlap, outputSpectrogram);

    // Output the spectrogram data (example)
    printf("Spectrogram:\n");
    for (int i = 0; i < segmentLen / 2 + 1; i++) {
        printf("Frequency Bin %d:\n", i);
        for (int j = 0; j < numSegments; j++) {
            printf("%.6f ", outputSpectrogram[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(signal);
    for (int i = 0; i < segmentLen / 2 + 1; i++) {
        free(outputSpectrogram[i]);
    }
    free(outputSpectrogram);
}

int main() {
	printf("Running from main() function\n");

	//test_generate_signal();

	//test_fir();
	//test_fft();
	//test_ifft();
	//test_cfft();
	//test_conv();
	//test_butterworth_bandpass();

	test_spectogram();

	return 0;
}