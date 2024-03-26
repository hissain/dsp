#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"


int test_fft(void) {

    int FFT_LEN = 256; // must be in form of 2^N for fast FFT

    float32_t testOutput[FFT_LEN];

    float32_t* input = &testInput_f32_1kHz_15kHz[0];
    float32_t* output = &testOutput[0];

    printf("Before FFT:\n");
    print_array(input, FFT_LEN);
    printf("\n");


    arm_rfft_fast_instance_f32 S; // FFT instance structure

    // Initialize the FFT instance
    arm_rfft_fast_init_f32(&S, FFT_LEN);    

    // Perform the FFT
    arm_rfft_fast_f32(&S, input, output, 0);

    printf("After FFT (input):\n");
    print_array(input, FFT_LEN);
    printf("\n");

    printf("After FFT (output):\n");
    print_array(output, FFT_LEN);
    printf("\n");

    //Take the maximum value as the main frequency position and value
    uint32_t maxIndex;
    float32_t maxValue;
    arm_max_f32(output, FFT_LEN, &maxValue, &maxIndex);

    printf("max index (freq): %d\n", maxIndex);
    printf("max value (strength): %F\n", maxValue);

    return 0;
}

int test_cfft(void) {

    int FFT_LEN = 320; // must be in form of 2^N for fast FFT

    float32_t testOutput[FFT_LEN];

    float32_t* input = &testInput_f32_1kHz_15kHz[0];
    float32_t* output = &testOutput[0];

    printf("Before FFT:\n");
    print_array(input, FFT_LEN);
    printf("\n");

    arm_rfft_instance_f32 S; // FFT instance structure
    arm_cfft_radix4_instance_f32 S_CFFT; // CFFT instance structure

    // Initialize the FFT instance
    arm_rfft_init_f32(&S, &S_CFFT, FFT_LEN, 0, 1);  
    arm_cfft_radix4_init_f32(&S_CFFT, FFT_LEN, 0, 1);  

    // Perform the FFT
    arm_rfft_f32(&S, input, output);

    printf("After FFT (input):\n");
    print_array(input, FFT_LEN);
    printf("\n");

    printf("After FFT (output):\n");
    print_array(output, FFT_LEN);
    printf("\n");

    //Take the maximum value as the main frequency position and value
    uint32_t maxIndex;
    float32_t maxValue;
    arm_max_f32(output, FFT_LEN, &maxValue, &maxIndex);

    printf("max index (freq): %d\n", maxIndex);
    printf("max value (strength): %F\n", maxValue);

    return 0;
}

int test_ifft(void) {

    //int FFT_LEN = 256;
    int FFT_LEN = 320;

    float32_t fftResult[2 * FFT_LEN];
    float32_t testOutputInverse[2 * FFT_LEN];

    float32_t fftResultReal[FFT_LEN];
    float32_t fftResultImag[FFT_LEN];

    //float32_t* input = &input_15kHz_1kHz_50fs[0];
    float32_t* input = &testInput_f32_1kHz_15kHz[0];

    arm_cfft_instance_f32 S; // FFT instance structure

    printf("\nBefore FFT :\n");
    print_array(input, FFT_LEN);
    printf("\n");

    for (int i = 0; i < FFT_LEN; i++)
        fftResult[i] = input[i];

    // Initialize the FFT instance
    arm_cfft_init_f32(&S, FFT_LEN);

    // Perform the CFFT (Complex FFT)
    arm_cfft_f32(&S, fftResult, 0, 1);

    for (int i = 0; i < FFT_LEN; i += 2){
        fftResultReal[i] = fftResult[i];
        fftResultImag[i] = fftResult[i + 1];
    }

    printf("After FFT (Real Part):\n");
    print_array(fftResultReal, FFT_LEN);
    printf("\n");

    
    printf("After FFT (Imag Part):\n");
    print_array(fftResultImag, FFT_LEN);
    printf("\n");

    // Determine the index corresponding to the frequency to remove
    // int frequencyToRemove = 1000; // Frequency to remove in Hz
    // int indexToRemove = frequencyToRemove * FFT_LEN / 48000; // Assuming sampling frequency is 48 kHz

    // // Zero out the frequency component in the FFT result
    // fftResultReal[indexToRemove] = 0.0f;
    // fftResultImag[indexToRemove] = 0.0f;

    // Perform Inverse FFT/ IFFT
    arm_cfft_f32(&S, fftResult, 1, 1); // 2nd last param = 1 means inverse ifftFlag set

    printf("\nAfter IFFT:\n");
    print_array(fftResult, FFT_LEN);
    printf("\n");

    return 0;
}

