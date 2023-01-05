#include <sys/time.h>
#include <stdio.h>
#include <limits.h>
#define TIME_T long long


TIME_T current_timestamp_in_ms() {
    struct timeval te;
    gettimeofday(&te, NULL);
    TIME_T milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;

    return milliseconds;
}

void print_duration(TIME_T start, TIME_T end) {
    TIME_T diff = end - start;

    printf("%lld", diff);
}

void measure_and_print(void (*fun)()) {
    TIME_T start = current_timestamp_in_ms();

    fun();

    TIME_T end = current_timestamp_in_ms();

    print_duration(start, end);
}

void ensure_arr_ordered(int const * const arr, int size) {
    int prev = INT_MIN;

    for (int i = 0; i < size; ++i) {
        if (prev > arr[i]) {
            exit(1);
        }
        prev = arr[i];
    }
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void fill_with_randoms_max(int *arr, size_t len, int max) {
    srand(time(0));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % max;
    }
}

void fill_with_randoms(int *arr, size_t len) {
    fill_with_randoms_max(arr, len, RAND_MAX);
}