

SORT_ARR_SIZE ?=10000

bubblesort:
	@echo "Sorting $(SORT_ARR_SIZE) elements"
	gcc -DARR_SIZE=$(SORT_ARR_SIZE) src/bubblesort.c -o out/bubblesort -lm -mcmodel=large && ./out/bubblesort || echo "Not in correct order"

bubblesort_omp:
	@echo "Sorting $(SORT_ARR_SIZE) elements"
	gcc -DARR_SIZE=$(SORT_ARR_SIZE) src/bubblesort.c -o out/bubblesort -fopenmp -lm -mcmodel=large && ./out/bubblesort || echo "Not in correct order"
