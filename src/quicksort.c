
#include "utils.h"

#ifndef SIZE
# define SIZE (1 * 1000 * 1000)
#endif

#ifndef N
# define N 4
#endif

int ARR[SIZE];

void bubblesort(int *const a, int size) {
    for (int n = size; n > 1; --n) {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a + i, a + i + 1);
            }
        }
    }
}

int partition(int *a, int lo, int hi) {
    int pivot = a[hi];

    int i = lo - 1;

    for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a + i, a + j);
        }
    }

    i++;
    swap(a + i, a + hi);

    return i;
}

void quicksort(int *const a, int const lo, int const hi) {


    if (lo >= hi || lo < 0) {
        return;
    }

    int const diff = hi - lo;
    if (diff < N) {
        bubblesort(a, diff);
    }

    int const p = partition(a, lo, hi);

    #pragma omp task default(none) firstprivate(a, lo, p)
    quicksort(a, lo, p - 1);

    #pragma omp task default(none) firstprivate(a, hi, p)
    quicksort(a, p + 1, hi);

}

void qs() {
    #pragma omp parallel default(none) shared(ARR)
    {
        #pragma omp single nowait
        quicksort(ARR, 0, SIZE - 1);
    }
}


int main() {
    fill_with_randoms(ARR, SIZE);

    measure_and_print(qs);

    ensure_arr_ordered(ARR, SIZE);

    return 0;
}