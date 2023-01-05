#!/usr/bin/env python3

import os
import subprocess
from pathlib import Path
import csv

# sort algos
sort_len_sizes = [
    1_000,
    2_500,
    5_000,
    10_000,
    25_000,
    50_000,
    100_000,
    250_000,
    # 500_000,
    # 1_000_000,
    # 2_500_000,
    # 5_000_000,
    # 10_000_000,
]

# matrix algos
matrix_sizes = [
    10,
    100,
    250,
    500,
    1_000,
    2_500,
    5_000,
    # 10_000,
    # 25_000,
]

cores = [
    1,
    2,
    4,
    8,
]


targets = [
    ("matrix", matrix_sizes),
    ("bucket", sort_len_sizes),
    ("brick", sort_len_sizes),
    ("counting", sort_len_sizes),
    ("insert", sort_len_sizes),
    ("selection", sort_len_sizes),
]

Path("out").mkdir(exist_ok=True)

with open("./out/times.cvs", "w+") as f:
    writer = csv.writer(f)
    writer.writerow(["Program", "Size", "Time"])

    for config in targets:
        target = config[0]
        sizes = config[1]

        for cur_cores in cores:
            for size in sizes:

                name = "{} - {} cores".format(target, cur_cores)

                print("Starting {}. CORES: {} SIZE: {}".format(target, cur_cores, size))

                env = dict(os.environ, SIZE=str(size), OMP_NUM_THREADS=str(cur_cores))

                make_target = "{}_omp".format(target)
                out = subprocess.run(["make", "-s", make_target], env=env, stdout=subprocess.PIPE).stdout.decode("utf-8")

                print(out)

                writer.writerow([name, size, out])

