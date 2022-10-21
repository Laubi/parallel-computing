#include <memory.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#ifndef ARR_LEN
# define ARR_LEN 1000
#endif

int A[ARR_LEN];

void sieve() {
    for( int i = 2; i < sqrt(ARR_LEN); i++) {
        if (A[i] == TRUE) {

            for(int j = 0; i*i + j*i < ARR_LEN; j++) {
                A[i*i + j*i] = FALSE;
            }
        }
    }
}

int main() {
    for(int i = 0; i < ARR_LEN; i++) {
        A[i] = TRUE;
    }

    sieve();

    return 0;
}