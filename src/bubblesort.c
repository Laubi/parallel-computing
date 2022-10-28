
#include <time.h>
#include <stdlib.h>
#include "utils.h"

#ifndef ARR_SIZE
#   define ARR_SIZE 1000
#endif

int ARR[ARR_SIZE];

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_SIZE; i++) {
        ARR[i] = rand();
    }
}

void bubblesort(int * a, int size) {
    for(int  n= size; n > 1; --n) {
        for (int i =0; i < n-1; ++i){
            if(a[i] > a[i+1]) {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }
}

void bubbleSort() {
    bubblesort(ARR, ARR_SIZE);
}

int main() {
    generateRandoms();

    measure_and_print(bubbleSort);

    return 0;
}