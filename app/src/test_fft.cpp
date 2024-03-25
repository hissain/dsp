#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"


int test_fft(void) {

    int FFT_LEN = 256; //TEST_LENGTH_SAMPLES;

    float32_t testOutput[2 * FFT_LEN];

    float32_t* input;
    float32_t* output;
    arm_rfft_fast_instance_f32 S; // FFT instance structure

    // Initialize the input signal (for example)
    input = &testInput_f32_1kHz_15kHz[0];
    output = &testOutput[0];

    // Initialize the FFT instance
    arm_rfft_fast_init_f32(&S, 2 * FFT_LEN);

    // Perform the FFT
    arm_rfft_fast_f32(&S, input, output, 0);

    printf("Output Real Part:\n");
    print_array(output, FFT_LEN);
    printf("\n");

    printf("Output Imaginary Part:\n");
    print_array(output + FFT_LEN, FFT_LEN);
    printf("\n");

    /* Take the absolute value of each calculation to get intensity of each frequency */
    //arm_cmplx_mag_f32(output, output, FFT_LEN);
    
    /* Take the maximum value as the main frequency position and value */
    uint32_t maxIndex;
    float32_t maxValue;
    arm_max_f32(output, FFT_LEN, &maxValue, &maxIndex);

    printf("max index (freq): %d\n", maxIndex);
    printf("max value (strength): %F\n", maxValue);

    return 0;
}

