#include <memory.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

uint_fast8_t ARR[SIZE];

void sieve() {
    size_t upper_bound = (size_t) sqrt(SIZE);

#pragma omp parallel for schedule(static)

    for (size_t i = 2; i < upper_bound; i+=2) {
        if (ARR[i] == true) {

           // size_t const upper =  (size_t) ceil((double)(SIZE - i * i) / i);
           // #pragma omp parallel for schedule(dynamic)
           // for (int j = 0; j < upper; j++) {
            for (int j = 0; i * i + j * i < SIZE; j++) {
                ARR[i * i + j * i] = false;
            }
        }
    }
}

int main() {
    memset(ARR, true, SIZE);

    measure_and_print(sieve);

    return 0;
}