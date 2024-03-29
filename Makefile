SIZE ?=1000
BUCKETS ?=10
N ?=8

define compile_and_run
	gcc 								\
		-DSIZE=$(SIZE)					\
		-DBUCKETS=$(BUCKETS)			\
		-DN=$(N)						\
		$(1) 						    \
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

