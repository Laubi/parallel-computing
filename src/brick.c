

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"

#ifndef ARR_SIZE
#   define ARR_SIZE 1000
#endif

int ARR[ARR_SIZE];


void generateRandoms() {
    srand(time(0));
    for (int i = 0; i < ARR_SIZE; i++) {
        ARR[i] = rand();
    }
}

void brick() {
    bool sorted = false;

    while(!sorted) {
        sorted = true;

#pragma omp parallel for schedule(static) default(none) shared(ARR) reduction(&&: sorted)
        for(int i = 1; i < ARR_SIZE -1; i +=2) {
            if (ARR[i] > ARR[i + 1]) {
                swap(ARR + i, ARR + i + 1);
                sorted = false;
            }
        }

#pragma omp parallel for schedule(static) default(none) shared(ARR) reduction(&&: sorted)
        for (int i = 0; i < ARR_SIZE -1; i += 2) {
            if (ARR[i] > ARR[i + 1]) {
                swap(ARR + i, ARR + i + 1);
                sorted = false;
            }
        }
    }
}

int main() {
    generateRandoms();

    measure_and_print(brick);

    ensure_arr_ordered(ARR, ARR_SIZE);

    return EXIT_SUCCESS;
}

