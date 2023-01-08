
#include <limits.h>
#include "utils.h"


#ifndef SIZE
#   define SIZE 20000
#endif

#ifndef BUCKETS
#   define BUCKETS 10
#endif

int ARR[SIZE];

int B[BUCKETS][SIZE] = {0};
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

void bucketSort() {
    int max = INT_MIN;

    for(int i = 0; i < SIZE; i++) {
        if (max < ARR[i]) {
            max = ARR[i];
        }
    }

    for(int i = 0; i < SIZE; i++) {
        int bucket_index = (BUCKETS * ARR[i]) / max;
        bucket_index = bucket_index +( bucket_index >= BUCKETS ?  -1 : 0);

        B[bucket_index][B_INDEX[bucket_index]] = ARR[i];
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
            ARR[off + k] = B[i][k];
        }
    }
}

int main() {
    fill_with_randoms_max(ARR, SIZE, 100);

    measure_and_print(bucketSort);

    ensure_arr_ordered(ARR, SIZE);

    return 0;
}