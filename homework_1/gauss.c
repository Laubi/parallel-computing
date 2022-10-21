
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#ifndef MATRIX_SIZE
#   define MATRIX_SIZE 10
#endif

int a[MATRIX_SIZE][MATRIX_SIZE];


void swap_rows(int h, int max) {
    for(int i = 0; i < MATRIX_SIZE; i++) {
        int t = a[h][i];
        a[h][i] = a[max][i];
        a[max][i] = t;
    }
}

void initializeWithRandoms() {
    srand(time(0));

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            a[i][j] = rand();
        }
    }
}

void gauss() {
    int h = 0;
    int k = 0;

    while(h < MATRIX_SIZE && k < MATRIX_SIZE) {
        int i_max = INT_MIN;

        for(int i = h; i < MATRIX_SIZE;   i++) {
            if (i_max < a[i][k]) {
                i_max = i;
            }
        }

        if (a[i_max][k] ==0) {
            k ++;
            continue;
        }

        swap_rows(h, i_max);

        for(int i = h+1; i < MATRIX_SIZE; i++) {
            double f = (double) a[i][k] / a[h][k];

            a[i][k] = 0;
            for(int j = k+1; j < MATRIX_SIZE; j++) {
                a[i][j] = a[i][j] - a[h][j] * f;
            }
        }
        h++;
        k++;
    }
}

int main() {
    initializeWithRandoms();

    gauss();

    return 0;
}