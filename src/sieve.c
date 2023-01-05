#include <memory.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

uint_fast8_t A[SIZE];

void sieve() {
    size_t upper_bound = (size_t) sqrt(SIZE);

    for (size_t i = 2; i < upper_bound; i++) {
        if (A[i] == true) {

            for (int j = 0; i * i + j * i < SIZE; j++) {
                A[i * i + j * i] = false;
            }
        }
    }
}

int main() {
    memset(A, true, SIZE);

    measure_and_print(sieve);

    return 0;
}