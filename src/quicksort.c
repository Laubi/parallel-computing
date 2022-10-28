
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifndef ARR_LEN
# define ARR_LEN 1000
#endif

int A[ARR_LEN];

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = rand();
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int lo, int hi) {
    int pivot = a[hi];

    int i = lo - 1;

    for(int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a + i, a + j);
        }
    }

    i++;
    swap(a+i, a+hi);

    return i;
}

void quicksort(int*a, int lo, int hi) {

    if (lo >=hi || lo < 0) {
        return;
    }

    int p = partition(a, lo, hi);

    quicksort(a, lo, p-1);
    quicksort(a, p+1, hi);
}

void qs(){
    quicksort(A, 0, ARR_LEN-1);
}


int main() {
    generateRandoms();

    measure_and_print(qs);

    return 0;
}