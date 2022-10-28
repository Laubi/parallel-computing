#include <memory.h>
#include <math.h>
#include <stdint.h>

#include "utils.h"

#define TRUE 1
#define FALSE 0

#ifndef ARR_LEN
# define ARR_LEN 1000
#endif

uint8_t A[ARR_LEN];

void sieve() {
    size_t upper_bound = (size_t) sqrt(ARR_LEN);

    for (size_t i = 2; i < upper_bound; i++) {
        if (A[i] == TRUE) {

            for (int j = 0; i * i + j * i < ARR_LEN; j++) {
                A[i * i + j * i] = FALSE;
            }
        }
    }
}

int main() {
    memset(A, TRUE, ARR_LEN);

    measure_and_print(sieve);

    return 0;
}