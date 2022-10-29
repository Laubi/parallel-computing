#!/usr/bin/env python3

import subprocess
from pathlib import Path
import csv

# sort algos
sort_len_sizes = [1_000, 2_500, 5_000, 10_000, 25_000, 50_000, 100_000, 250_000, 500_000, 1_000_000]

# matrix algos
matrix_sizes = [10, 100, 250, 500, 1_000, 2_500, 5_000, 10_000, 25_000]

# sieve
sieve_sizes = [10_000, 100_000, 250_000, 500_000, 1_000_000, 10_000_000, 100_000_000]

configs = [
    ("bubblesort", "bubblesort.c", ("ARR_LEN", sort_len_sizes)),
    ("bucket", "bucket.c", ("ARR_LEN", sort_len_sizes)),
    ("counting", "counting.c", ("ARR_LEN", sort_len_sizes)),
    ("insert", "insert.c", ("ARR_LEN", sort_len_sizes)),
    ("quicksort", "quicksort.c", ("ARR_LEN", sort_len_sizes)),
    ("selection", "selection.c", ("ARR_LEN", sort_len_sizes)),
    ("sieve", "sieve.c", ("ARR_LEN", sort_len_sizes)),
    ("matrix", "matrix.c", ("MATRIX_SIZE", matrix_sizes)),
    ("dijkstra", "dijkstra.c", ("MATRIX_SIZE", matrix_sizes)),
    ("gauss", "gauss.c", ("MATRIX_SIZE", matrix_sizes))
]

Path("out").mkdir(exist_ok=True)
with open("./out/times.cvs", "w+") as f:
    writer = csv.writer(f)
    writer.writerow(["Program", "Size", "Time"])

    for config in configs:
        k = config[0]
        s = config[1]
        p = config[2]

        variations = map(lambda v: (p[0], v), p[1])

        for variation in variations:

            print("Starting {}: {}".format(k, variation[1]))

            source_file = "src/{}".format(s)
            program_name = "out/{}".format(k)

            preprocessor_var = "-D{}={}".format(variation[0], variation[1])

            out = subprocess.run(["gcc", "-mcmodel=large", preprocessor_var, source_file, "-lm", "-o", program_name], stdout=subprocess.PIPE).stdout.decode("utf-8")
            print(out)


            time = subprocess.run([program_name], stdout=subprocess.PIPE).stdout.decode("utf-8")
            print(time)

            writer.writerow([k, variation[1], time])

