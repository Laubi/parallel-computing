
#include <time.h>
#include <stdlib.h>

#ifndef ARR_SIZE
#   define ARR_SIZE 100000
#endif

int ARR[ARR_SIZE];

void generateRandoms() {
    srand(time(0));
    for(int i = 0; i < ARR_SIZE; i++) {
        ARR[i] = rand();
    }
}

void bubblesort() {
    for(int  n= ARR_SIZE; n > 1; --n) {
        for (int i =0; i < n-1; ++i){
            if(ARR[i] > ARR[i+1]) {
                int t = ARR[i];
                ARR[i] = ARR[i+1];
                ARR[i+1] = t;
            }
        }
    }
}

int main() {
    generateRandoms();
    bubblesort();
}