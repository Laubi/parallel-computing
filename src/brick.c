

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 1000
#endif

int ARR[SIZE];

void brick() {
    bool sorted = false;

    while(!sorted) {
        sorted = true;

#pragma omp parallel for schedule(static) default(none) shared(ARR) reduction(&&: sorted)
        for(int i = 1; i < SIZE - 1; i +=2) {
            if (ARR[i] > ARR[i + 1]) {
                swap(ARR + i, ARR + i + 1);
                sorted = false;
            }
        }

#pragma omp parallel for schedule(static) default(none) shared(ARR) reduction(&&: sorted)
        for (int i = 0; i < SIZE - 1; i += 2) {
            if (ARR[i] > ARR[i + 1]) {
                swap(ARR + i, ARR + i + 1);
                sorted = false;
            }
        }
    }
}

int main() {
    fill_with_randoms(ARR, SIZE);

    measure_and_print(brick);

    ensure_arr_ordered(ARR, SIZE);

    return EXIT_SUCCESS;
}

