
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 1000
#endif

#ifndef MAX
#   define MAX 100
#endif


int A[SIZE];
int O[SIZE];

int COUNT[MAX + 1] = {0};

void countingSort(){
    for(int i = 0; i < SIZE; i++) {
        COUNT[A[i]]++;
    }

    for(int i = 1; i < MAX; i++) {
        COUNT[i] += COUNT[i-1];
    }

    for(int i = SIZE - 1; i >= 0; i--) {
        O[--COUNT[A[i]]] = A[i];
    }

    memcpy(A, O, sizeof(A));
}

int main() {
    fill_with_randoms_max(A, SIZE, MAX);

    measure_and_print(countingSort);

    ensure_arr_ordered(A, SIZE);

    return EXIT_SUCCESS;
}