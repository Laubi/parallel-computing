SIZE ?=1000
BUCKETS ?=10

define compile_and_run
	gcc 								\
		-DARR_SIZE=$(SIZE)							\
		-DARR_LEN=$(SIZE)							\
		-DMATRIX_SIZE=$(SIZE)							\
		-DBUCKETS=$(BUCKETS)							\
		$(1) 						\
		-o out/$(2) 					\
		-O0								\
		$(3)  							\
		-mcmodel=large 					\
		-lm								\

	./out/$(2)
endef

%: src/%.c
	$(call compile_and_run,$<,$@)

%_omp: src/%.c
	$(call compile_and_run,$<,$@,-fopenmp)

