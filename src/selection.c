
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifndef ARR_LEN
# define ARR_LEN 1000
#endif

int A[ARR_LEN];

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = rand();
    }
}

void selectionSort() {

    for(int i = 0; i < ARR_LEN-1; i++) {
        int jMin = i;
        for(int j = i+1; j < ARR_LEN; j++) {
            if (A[j] < A[jMin]) {
                jMin = j;
            }
        }

        if (jMin != i) {
            int t = A[i];
            A[i] = A[jMin];
            A[jMin] = t;
        }
    }
}


int main() {
    generateRandoms();

    measure_and_print(selectionSort);

    return 0;
}