#include <stdio.h>
#include "dsp.h"

void print_array(float32_t *data, int size){
    printf("Printing Array:\n");
    for(int i = 0; i < size; i++){
        printf("%f, ", data[i]);
    }
    printf("\n");
}

void generate_composit(float32_t fs, float32_t freq[], int freqLen, int n_samples, float32_t *freqOut){
    float dt = 1.0f / fs; // Time step
    float t[n_samples]; // Time array

    // Generate time array
    for (int i = 0; i < n_samples; i++) {
        t[i] = i * dt;
    }

    // Generate signal at 1 kHz
    for (int i = 0; i < n_samples; i++) {
        freqOut[i] = 0;
    }

    for (int f = 0; f < freqLen; f++){

        // Generate signal at 15 kHz
        for (int i = 0; i < n_samples; i++) {
            freqOut[i] += sin(2 * M_PI * freq[f] * t[i]);
        }
    }

    // Print the composite signal
    // printf("Composite signal:\n");
    // for (int i = 0; i < n_samples; i++) {
    //     printf("%.2f ", freqOut[i]);
    // }
}