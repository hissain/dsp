#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"

/* -------------------------------------------------------------------
 * Declare Test output buffer
 * ------------------------------------------------------------------- */
static float32_t testOutput[TEST_LENGTH_SAMPLES];

/*
* fftSize: This parameter specifies the size of the FFT. It should be an integer 
* power of 4, as the radix-4 algorithm is used. Common values include 16, 64, 256, etc., 
* depending on the size of your input data and the resolution you need in the frequency domain.
* ifftFlag: This parameter determines whether the FFT operation will be forward (FFT) or 
* inverse (IFFT). Set it to 0 for FFT or 1 for IFFT. doBitReverse: This parameter specifies 
* whether to perform bit reversal during the FFT computation. Set it to 1 to enable bit 
* reversal or 0 to disable it.
*/
uint16_t  fftSize = 256;
uint8_t ifftFlag = 0;
uint8_t doBitReverse = 1;

/* ----------------------------------------------------------------------
 * FIR LPF Example
 * ------------------------------------------------------------------- */
int test_fft(void)
{
    uint32_t i;
    float32_t  *inputF32, *outputF32;

    /* Initialize input and output buffer pointers */
    inputF32 = &testInput_f32_1kHz_15kHz[0];
    outputF32 = &testOutput[0];

    /* Declare the structure parameter of FFT */
    arm_cfft_radix4_instance_f32 S;
    float32_t maxValue;
    /* Init FFT/IFFT */
    arm_cfft_radix4_init_f32(&S, fftSize, ifftFlag, doBitReverse);
    /* Perform an FFT operation and return the result to the original input array */
    arm_cfft_radix4_f32(&S, inputF32);
    /* Take the absolute value of each calculation to get intensity of each frequency */
    arm_cmplx_mag_f32(inputF32, testOutput, fftSize);
    
    /* Take the maximum value as the main frequency position and value */
    uint32_t testIndex;
    arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);

    print_array(inputF32, 100);
    print_array(outputF32, 100);

    printf("arm_max_f32 index (freq): %d\n", testIndex);

    return 0;
}