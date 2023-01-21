
#include <math.h>
#include "utils.h"

#ifndef SIZE
#   define M 3 //rows
#   define N 4 //cols
#else
#   define M SIZE
#   define N SIZE
#endif

double MATRIX[M][N];


void swap_rows(int r1, int r2) {
    for (int i = 0; i < N; i++) {
        dswap(&MATRIX[r1][i], &MATRIX[r2][i]);
    }
}

// https://en.wikipedia.org/wiki/Gaussian_elimination#Pseudocode
void gauss() {
    int h = 0;
    int k = 0;

    while (h < M && k < N) {

        // Find the k-th pivot:
        int i_max = h;
        for (int i = h; i < M; i++) {
            if (fabs(MATRIX[i_max][k]) < fabs(MATRIX[i][k])) {
                i_max = i;
            }
        }

        if (MATRIX[i_max][k] == 0) {
            k++;
            continue;
        }

        swap_rows(h, i_max);


        #pragma omp parallel for schedule(static) default(none) shared(MATRIX) firstprivate(h, k)
        for (int i = h + 1; i < M; i++) {
            double f = (double) MATRIX[i][k] / MATRIX[h][k];

            MATRIX[i][k] = 0;
            for (int j = k + 1; j < N; j++) {
                MATRIX[i][j] -= MATRIX[h][j] * f;
            }
        }


        h++;
        k++;
    }
}

int main() {
    dfill_with_randoms((double*)MATRIX, M * N);

    measure_and_print(gauss);

    return 0;
}