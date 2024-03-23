#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"

/* ----------------------------------------------------------------------
** Macro Defines
** ------------------------------------------------------------------- */
#define TEST_LENGTH_SAMPLES         320
#define NUM_TAPS                    29
#define NUM_TAPS_ARRAY_SIZE         29
/* -------------------------------------------------------------------
 * Declare Test output buffer
 * ------------------------------------------------------------------- */
static float32_t testOutput[TEST_LENGTH_SAMPLES];

const float32_t firCoeffs32[NUM_TAPS_ARRAY_SIZE] = {
    -0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f,
    -0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f,
    +0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f,
    +0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f
};


/* ----------------------------------------------------------------------
 * Conv Example
 * ------------------------------------------------------------------- */
int test_conv(void)
{
    float32_t  *inputF32, *outputF32;

    /* Initialize input and output buffer pointers */
    inputF32 = &testInput_f32_1kHz_15kHz[0];
    outputF32 = &testOutput[0];

    /* Call conv function. */
    arm_conv_f32(inputF32, TEST_LENGTH_SAMPLES, firCoeffs32, NUM_TAPS, outputF32);

    print_array(inputF32, 10);
    print_array(outputF32, 10);

    return 0;
}