# Advent of Code 2015

🎅🎄
Aoc15 is a project for solving [AoC15](https://adventofcode.com/2015/) problems.

## Build

To compile project, you must have compiler with c++17 support and cmake version at least 3.10.2.
```sh
mkdir build
cd build
cmake ../
make
```

## Test

Running tests is also very simple.
```sh
# without compilation
make test

# with compilation
make check
```

## Usage

Project will compile binaries for all days. To solve problems run:
```sh
./aoc15-dXY <FILE>
```

## Licensing

This project is under the [MIT License](LICENSE.md).
