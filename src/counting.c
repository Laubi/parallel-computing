
#include <stdlib.h>
#include <memory.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 1000
#endif

#ifndef MAX
#   define MAX 100
#endif


int ARR[SIZE];
int O[SIZE];

int COUNT[MAX + 1] = {0};

void countingSort(){
#pragma omp parallel for schedule(static) reduction(+:count[:])
    for(int i = 0; i < SIZE; i++) {
        COUNT[ARR[i]]++;
    }

    for(int i = 1; i < MAX; i++) {
        COUNT[i] += COUNT[i-1];
    }

    for(int i = SIZE - 1; i >= 0; i--) {
        O[--COUNT[ARR[i]]] = ARR[i];
    }

    memcpy(ARR, O, sizeof(ARR));
}

int main() {
    fill_with_randoms_max(ARR, SIZE, MAX);

    measure_and_print(countingSort);

    ensure_arr_ordered(ARR, SIZE);

    return EXIT_SUCCESS;
}