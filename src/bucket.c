
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include "utils.h"


#ifndef ARR_LEN
#   define ARR_LEN 20000
#endif

#ifndef BUCKETS
#   define BUCKETS 10
#endif

int A[ARR_LEN];

int B[BUCKETS][ARR_LEN] = {0};
int B_INDEX[BUCKETS] = {0};

void insertSort(int *a, int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j> 0 && a[j-1] > a[j]; j--) {
            int t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
        }
    }
}

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = rand() % 100;
    }
}

void bucketSort() {
    int max = INT_MIN;

    for(int i = 0; i < ARR_LEN; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }

    for(int i = 0; i < ARR_LEN; i++) {
        int bucket_index = (BUCKETS * A[i]) / max;
        bucket_index = bucket_index +( bucket_index >= BUCKETS ?  -1 : 0);

        B[bucket_index][B_INDEX[bucket_index]] = A[i];
        B_INDEX[bucket_index]++;
    }

    #pragma omp parallel for schedule(static)
    for(int i = 0; i < BUCKETS; i++){
        insertSort(B[i], B_INDEX[i]);

        int off = 0;
        for(int j = 0; j < i; j++) {
            off += B_INDEX[j];
        }

        for(int k =0; k < B_INDEX[i]; k++) {
            A[off+k] = B[i][k];
        }
    }
}

int main() {
    generateRandoms();

    measure_and_print(bucketSort);

    ensure_arr_ordered(A, ARR_LEN);

    return 0;
}