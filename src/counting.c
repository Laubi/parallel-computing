
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "utils.h"

#ifndef ARR_LEN
#   define ARR_LEN 1000
#endif

#ifndef MAX
#   define MAX 100
#endif


int A[ARR_LEN];
int O[ARR_LEN];

int COUNT[MAX + 1] = {0};

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = rand() % MAX;
    }
}

void countingSort(){
    for(int i = 0; i < ARR_LEN; i++) {
        COUNT[A[i]]++;
    }

    for(int i = 1; i < MAX; i++) {
        COUNT[i] += COUNT[i-1];
    }

    for(int i = ARR_LEN -1; i >=0; i--) {
        O[--COUNT[A[i]]] = A[i];
    }

    memcpy(A, O, sizeof(A));
}

int main() {
    generateRandoms();

    measure_and_print(countingSort);

    ensure_arr_ordered(A, ARR_LEN);

    return EXIT_SUCCESS;
}