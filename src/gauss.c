
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 10
#endif

int a[SIZE][SIZE];


void swap_rows(int h, int max) {
    for(int i = 0; i < SIZE; i++) {
        int t = a[h][i];
        a[h][i] = a[max][i];
        a[max][i] = t;
    }
}

void gauss() {
    int h = 0;
    int k = 0;

    while(h < SIZE && k < SIZE) {
        int i_max = INT_MIN;

        for(int i = h; i < SIZE; i++) {
            if (i_max < a[i][k]) {
                i_max = i;
            }
        }

        if (a[i_max][k] ==0) {
            k ++;
            continue;
        }

        swap_rows(h, i_max);

        for(int i = h+1; i < SIZE; i++) {
            double f = (double) a[i][k] / a[h][k];

            a[i][k] = 0;
            for(int j = k+1; j < SIZE; j++) {
                a[i][j] = a[i][j] - a[h][j] * f;
            }
        }
        h++;
        k++;
    }
}

int main() {
    fill_with_randoms(a, SIZE * SIZE);

    initializeWithRandoms();

    measure_and_print(gauss);

    return 0;
}