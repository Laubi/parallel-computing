
#include <time.h>
#include <stdlib.h>

#ifndef MATRIX_SIZE
#   define MATRIX_SIZE 1000
#endif

int a[MATRIX_SIZE][MATRIX_SIZE];

void initializeWithRandoms() {
    srand(time(0));

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            a[i][j] = rand() % 10;
        }
    }
}

void gauss() {
    for(int k = 0; k < MATRIX_SIZE; k++) {
        for(int i = 0; i < MATRIX_SIZE; i++) {
            int pivot = a[i][k];

            for(int j = 0; j < MATRIX_SIZE; j++) {
                if (i != k) {
                    int pivot_mult = pivot*a[k][j];
                    int el_mult = a[k][k] * a[i][j];
                    a[i][j] = el_mult - pivot_mult;
                }
            }
        }
    }
}

int main() {
    initializeWithRandoms();
    gauss();
}