#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 10000
#endif

int32_t a[SIZE][SIZE];
int32_t b[SIZE][SIZE];
int64_t c[SIZE][SIZE];

void multiply();

int main() {

    fill_with_randoms((int*)a, SIZE * SIZE);
    fill_with_randoms((int*)b, SIZE * SIZE);

    measure_and_print(multiply);

    return 0;
}

void multiply() {
#pragma omp parallel for schedule(static)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += a[i][k] * b[k][j];
            }

            c[i][j] = sum;
        }
    }
}