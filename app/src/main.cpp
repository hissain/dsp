#include <stdio.h>
#include <dsp/basic_math_functions.h>
#include "dsp.h"

#define SZ 5

int main() {
	printf("Running from main() function\n");

	float64_t A[SZ] = {1, 2, 3, 4, 5};
	float64_t B[SZ] = {1, 2, 3, 4, 5};
	float64_t C[SZ];

	arm_mult_f64(A, B, C, SZ);

	printf("C = [");
	for (int i = 0; i < SZ; i++){
		printf("%F ", C[i]);
	}
	printf("]\n");
	
	//test_fir();
	test_fft();
	test_ifft();
	//test_conv();
	//test_butterworth_bandpass();

	return 0;
}