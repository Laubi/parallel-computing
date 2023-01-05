
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 1000
#endif

int ARR[SIZE];

void generateRandoms() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
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
    bubblesort(ARR, SIZE);
}

int validate_order() {
    int min = INT_MIN;

    for (int i = 1; i < SIZE; i++) {
        if (min > ARR[i]) {
            return 0;
        }
        min = ARR[i];
    }

    return 1;
}

int main() {
#ifndef TIMING
    printf("Sorting %d elements\n", SIZE);
#endif

    generateRandoms();

    measure_and_print(bubbleSort);


    ensure_arr_ordered(ARR, SIZE);
#ifndef TIMING
    if(validate_order()) {
        puts("Correct order");
    } else {
        puts("Wrong order");
    }
#endif
}


