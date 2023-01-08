
#include "utils.h"

#ifndef SIZE
# define SIZE 1000
#endif

int ARR[SIZE];

void selectionSort() {

    for(int i = 0; i < SIZE - 1; i++) {
        int jMin = i;

        for(int j = i+1; j < SIZE; j++) {
            if (ARR[j] < ARR[jMin]) {
                jMin = j;
            }
        }

        if (jMin != i) {
            swap(ARR + i, ARR + jMin);
        }
    }
}


int main() {
    fill_with_randoms(ARR, SIZE);

    measure_and_print(selectionSort);

    ensure_arr_ordered(ARR, SIZE);

    return 0;
}