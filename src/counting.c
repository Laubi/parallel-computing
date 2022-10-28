
#include <stdlib.h>
#include <time.h>

#ifndef ARR_LEN
#   define ARR_LEN 1000
#endif

#ifndef MAX
#   define MAX 100
#endif


int A[ARR_LEN];
int O[ARR_LEN];

int COUNT[MAX + 1] = {0};

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = rand() % MAX;
    }
}

void countingSort(){
    for(int i = 0; i < ARR_LEN; i++) {
        COUNT[A[i]]++;
    }

    for(int i = 1; i < MAX; i++) {
        COUNT[i] = COUNT[i] + COUNT[i-1];
    }

    for(int i = ARR_LEN -1; i >=0; i--) {
        int j = A[i];
        COUNT[j]--;
        O[COUNT[j]] = A[i];
    }
}

int main() {
    generateRandoms();

    countingSort();


    return 0;
}