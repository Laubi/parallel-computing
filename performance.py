#!/usr/bin/env python3

import subprocess
from pathlib import Path


class Variation:
    def __init__(self, key: str, value):
        self.key = key
        self.value = value

    def __str__(self):
        return "-D{}={}".format(self.key, self.value)


class Program:
    source: str
    variations: tuple[str, list[int]]

    def __init__(self, source: str, variations: tuple[str, list[int]]):
        self.source = source
        self.variations = variations

    def configurations(self) -> list[Variation]:
        variations: list[Variation] = []

        key = self.variations[0]

        for val in self.variations[1]:
            variations.append(Variation(key, val))

        return variations


configs: dict[str, Program] = {
    "quicksort": Program(
        "quicksort.c",
        ("ARR_LEN", [1000, 10000, 100000]),
    ),
}

Path("out").mkdir(exist_ok=True)

for k, v in configs.items():
    for variation in v.configurations():

        source_file = "src/{}".format(v.source)
        program_name = "out/{}".format(k)
        params = ["gcc", "-lm", "-pg", str(variation), source_file, "-o", program_name]

        print(params)

        subprocess.run(args=params)
        subprocess.run([program_name])
        subprocess.run(["gprof", program_name, "gmon.out", "-b", "--no-graph"])


