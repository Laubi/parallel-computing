

bubblesort:
	gcc -DARR_SIZE=10000 src/bubblesort.c -o out/bubblesort -lm -mcmodel=large && ./out/bubblesort

bubblesort_omp:
	gcc -DARR_SIZE=10000 src/bubblesort.c -o out/bubblesort -fopenmp -lm -mcmodel=large && ./out/bubblesort
