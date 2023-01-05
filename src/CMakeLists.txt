cmake_minimum_required(VERSION 3.22)

project(uni)
set (CMAKE_CXX_STANDARD 11)

add_executable(matrix matrix.c)
add_executable(bubblesort bubblesort.c)
add_executable(gauss gauss.c)
add_executable(sieve sieve.c)

add_executable(bucket bucket.c)

add_executable(counting counting.c)
add_executable(insert insert.c)
add_executable(selection selection.c)
add_executable(quicksort quicksort.c)
add_executable(dijkstra dijkstra.c)

add_executable(brick brick.c)