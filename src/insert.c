
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

int A[SIZE];

void insertSort() {
    for(int i = 1; i < SIZE; i++) {
        for(int j = i; j> 0 && A[j-1] > A[j]; j--) {
            int t = A[j];
            A[j] = A[j-1];
            A[j-1] = t;
        }
    }
}


int main() {
    fill_with_randoms(A, SIZE);

    measure_and_print(insertSort);

    return 0;
}