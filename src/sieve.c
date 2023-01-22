#include <memory.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <omp.h>

#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

uint_fast8_t ARR[SIZE];

void sieve() {
    size_t upper_bound = (size_t) sqrt(SIZE);

#ifdef _OPENMP
    #pragma omp parallel for schedule(static) default(none) shared(ARR) firstprivate(upper_bound)
    for (size_t i = 2 + omp_get_thread_num(); i < upper_bound; i+= omp_get_num_threads()) {
#else
    for (size_t i = 2; i < upper_bound; i++) {
#endif
        if (ARR[i] == true) {
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