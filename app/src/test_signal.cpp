#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"


void test_generate_signal(void) {

    #define SZ 1024
    #define FS 1000

    float32_t freq[] = {150, 17, 10, 5};
    float32_t ampl[] = {25.5f, 0.8f, 1.0f, 2.0f};
	float32_t freqOut[SZ] = {0, };

	generate_composit(FS, freq, ampl, 4, SZ, freqOut);
	print_array(freqOut, SZ);
}

