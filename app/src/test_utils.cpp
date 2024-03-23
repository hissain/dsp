#include <stdio.h>
#include "dsp.h"

void print_array(float32_t *data, int size){
    printf("Printing Array:\n");
    for(int i = 0; i < size; i++){
        printf("%f, ", data[i]);
    }
    printf("\n");
}