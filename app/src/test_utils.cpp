#include <stdio.h>
#include <assert.h>
#include "dsp.h"

void print_array(float32_t *data, int size){
    printf("Printing Array:\n");
    for(int i = 0; i < size; i++){
        printf("%f, ", data[i]);
    }
    printf("\n");
}

void generate_composit(float32_t fs, float32_t freq[], float32_t ampl[], int freqLen, int n_samples, float32_t *freqOut){
    float dt = 1.0f / fs; // Time step
    float *t = (float*)malloc(n_samples * sizeof(float)); // Time array

    assert(t != NULL);

    // Generate time array
    for (int i = 0; i < n_samples; i++) {
        t[i] = i * dt;
    }

    for (int i = 0; i < n_samples; i++) {
        freqOut[i] = 0;
    }

    for (int f = 0; f < freqLen; f++){
        for (int i = 0; i < n_samples; i++) {
            freqOut[i] += (ampl[f] * sin(2 * M_PI * freq[f] * t[i]));
        }
    }
    free(t);
}