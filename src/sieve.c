#include <memory.h>
#include <math.h>
#include <stdint.h>

#include "utils.h"

#define TRUE 1
#define FALSE 0

#ifndef SIZE
# define SIZE 1000
#endif

uint8_t A[SIZE];

void sieve() {
    size_t upper_bound = (size_t) sqrt(SIZE);

    for (size_t i = 2; i < upper_bound; i++) {
        if (A[i] == TRUE) {

            for (int j = 0; i * i + j * i < SIZE; j++) {
                A[i * i + j * i] = FALSE;
            }
        }
    }
}

int main() {
    memset(A, TRUE, SIZE);

    measure_and_print(sieve);

    return 0;
}