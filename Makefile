.PHONY: all

all: MatrixMult Concat Regexp
	@echo "Done."

MatrixMult: MatrixMultC
Concat: ConcatC
Regexp: RegexpC

MatrixMultC: D=src/c
MatrixMultC: MatrixMult1C MatrixMult2C MatrixMult3C

ConcatC: D=src/c
ConcatC: Concat1C Concat2C Concat3C

RegexpC: D=src/c
RegexpC: Regexp1C Regexp2C Regexp3C

include src/c/Makefile

