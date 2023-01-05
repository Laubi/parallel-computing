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

void initializeWithRandoms();
void multiply();

int main() {
    srand(time(0));


    initializeWithRandoms();

    measure_and_print(multiply);

    return 0;
}

void initializeWithRandoms() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
}

void multiply() {
#pragma omp parallel
#pragma omp for schedule(static)
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