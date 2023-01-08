
#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

int ARR[SIZE];

void insertSort() {
    for(int i = 1; i < SIZE; i++) {
        for(int j = i; j> 0 && ARR[j - 1] > ARR[j]; j--) {
            int t = ARR[j];
            ARR[j] = ARR[j - 1];
            ARR[j - 1] = t;
        }
    }
}


int main() {
    fill_with_randoms(ARR, SIZE);

    measure_and_print(insertSort);

    return 0;
}