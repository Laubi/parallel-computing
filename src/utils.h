#include <sys/time.h>
#include <stdio.h>

#define TIME_T long long


TIME_T current_timestamp_in_ms() {
    struct timeval te;
    gettimeofday(&te, NULL);
    TIME_T milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;

    return milliseconds;
}

void print_duration(TIME_T start, TIME_T end) {
    TIME_T diff = end - start;

    printf("%lld\n", diff);
}

void measure_and_print(void (*fun)()) {
    TIME_T start = current_timestamp_in_ms();

    fun();

    TIME_T end = current_timestamp_in_ms();

    print_duration(start, end);
}