
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>


#ifndef ARR_LEN
# define ARR_LEN 100
#endif

#define BUCKETS 10

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
        A[i] = rand();
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
        int bucket_index = (int) floor((double) (A[i]) / max * BUCKETS) % 10;
        int inner_bucket_index = B_INDEX[bucket_index];

        B[bucket_index][inner_bucket_index] = A[i];
        B_INDEX[bucket_index]++;
    }

    int pos = 0;
    for(int i = 0; i < BUCKETS; i++){
        insertSort(B[i], B_INDEX[i]);

        for(int k =0; k < B_INDEX[k]; k++) {
            A[pos++] = B[i][k];
        }
    }
}

int main() {
    generateRandoms();
    bucketSort();


    return 0;
}