#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "utils.h"

#ifndef MATRIX_SIZE
#   define MATRIX_SIZE 10000
#endif

int32_t a[MATRIX_SIZE][MATRIX_SIZE];
int32_t b[MATRIX_SIZE][MATRIX_SIZE];
int64_t c[MATRIX_SIZE][MATRIX_SIZE];

void initializeWithRandoms();
void multiply();

int main() {
    srand(time(0));


    initializeWithRandoms();

    measure_and_print(multiply);

    return 0;
}

void initializeWithRandoms() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
}

void multiply() {
#pragma omp parallel
#pragma omp for schedule(static)
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sum += a[i][k] * b[k][j];
            }

            c[i][j] = sum;
        }
    }
}