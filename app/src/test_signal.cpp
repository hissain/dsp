#include <stdio.h>
#include "dsp.h"
#include "arm_math.h"
#include "dsp/transform_functions.h"


void test_generate_signal(void) {

    #define SZ 256
    #define FS 50000

    float32_t freq[] = {15000, 1000};
	float32_t freqOut[SZ] = {0, };

	generate_composit(FS, freq, 2, SZ, freqOut);
	print_array(freqOut, SZ);
}

