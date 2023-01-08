
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 1000
#endif

int ARR[SIZE];

void bubblesort(int *a, int size) {
#pragma omp parallel for schedule(static) default(none) private(size) shared(a)
    for (int n = size; n > 1; --n) {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a + i, a + i + 1);
            }
        }
    }
}

void bubbleSort() {
    bubblesort(ARR, SIZE);
}


int main() {
    fill_with_randoms(ARR, SIZE);

    measure_and_print(bubbleSort);


    ensure_arr_ordered(ARR, SIZE);
}


