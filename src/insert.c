
#include <stdlib.h>
#include <time.h>

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

void insertSort() {
    for(int i = 1; i < ARR_LEN; i++) {
        for(int j = i; j> 0 && A[j-1] > A[j]; j--) {
            int t = A[j];
            A[j] = A[j-1];
            A[j-1] = t;
        }
    }
}


int main() {
    generateRandoms();

    insertSort();

    return 0;
}