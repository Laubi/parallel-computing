
#include <math.h>
#include "utils.h"

#ifndef SIZE
#   define SIZE 3
#endif

int a[SIZE][SIZE] = {
        {
                2,  1,  -1
        },
        {
                -1, -3, 1
        },
        {
                1,  8,  -2
        }
};


void swap_rows(int r1, int r2) {
    for (int i = 0; i < SIZE; i++) {
        swap(&a[r1][i], &a[r2][i]);
    }
}

// https://en.wikipedia.org/wiki/Gaussian_elimination#Pseudocode
void gauss() {
    int h = 0;
    int k = 0;
    const int sqrt_n = sqrt(SIZE);

    while (h < SIZE && k < SIZE) {

        // Find the k-th pivot:
        int i_max = h;
        for (int i = h; i < SIZE; i++) {
            if (a[i_max][k] < a[i][k]) {
                i_max = i;
            }
        }

        if (a[i_max][k] == 0) {
            k++;
            continue;
        }

        swap_rows(h, i_max);

        for (int i = h + 1; i < SIZE; i++) {
            double f = (double) a[i][k] / a[h][k];

            a[i][k] = 0;
            for (int j = k + 1; j < SIZE; j++) {
                a[i][j] = a[i][j] - a[h][j] * f;
            }
        }

        h++;
        k++;
    }
}

int main() {
    //fill_with_randoms(a, SIZE * SIZE);

    measure_and_print(gauss);

    return 0;
}