
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

int A[SIZE];

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < SIZE; i++) {
        A[i] = rand();
    }
}

void selectionSort() {

    for(int i = 0; i < SIZE - 1; i++) {
        int jMin = i;

        for(int j = i+1; j < SIZE; j++) {
            if (A[j] < A[jMin]) {
                jMin = j;
            }
        }

        if (jMin != i) {
            swap(A+i, A + jMin);
        }
    }
}


int main() {
    generateRandoms();

    measure_and_print(selectionSort);

    ensure_arr_ordered(A, SIZE);

    return 0;
}