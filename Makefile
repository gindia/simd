.PHONY: run

run:
	# NOTE: add -mavx512f flag if AVX512 supported.
	clang main.c -o main -Wall -mavx -O3
	./main

