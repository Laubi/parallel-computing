SIZE ?=1000

define compile_and_run
	gcc 								\
		$(2) 							\
		src/$(1).c 						\
		-o out/$(1) 					\
		-O0								\
		$(3) -lm -mcmodel=large 		\

	./out/$(1)
	@echo
endef


bubblesort:
	$(call compile_and_run,bubblesort,-DARR_SIZE=$(SIZE))

bubblesort_omp:
	$(call compile_and_run,bubblesort,-DARR_SIZE=$(SIZE),-fopenmp)

matrix:
	$(call compile_and_run,matrix,-DMATRIX_SIZE=$(SIZE))

matrix_omp:
	$(call compile_and_run,matrix,-DMATRIX_SIZE=$(SIZE),-fopenmp)
