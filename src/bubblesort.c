
#include <time.h>
#include <stdlib.h>
#include <limits.h>
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

void bubblesort(int *a, int size) {
#pragma omp parallel for schedule(static) default(none) private(size) shared(a)
    for (int n = size; n > 1; --n) {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
}

void bubbleSort() {
    bubblesort(ARR, ARR_SIZE);
}

int validate_order() {
    int min = INT_MIN;

    for (int i = 1; i < ARR_SIZE; i++) {
        if (min > ARR[i]) {
            return 0;
        }
        min = ARR[i];
    }

    return 1;
}

int main() {
#ifndef TIMING
    printf("Sorting %d elements\n", ARR_SIZE);
#endif

    generateRandoms();

    measure_and_print(bubbleSort);


    ensure_arr_ordered(ARR, ARR_SIZE);
#ifndef TIMING
    if(validate_order()) {
        puts("Correct order");
    } else {
        puts("Wrong order");
    }
#endif
}


