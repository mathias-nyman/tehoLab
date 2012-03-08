.PHONY: all

all: MatrixMult Concat Regexp
	@echo "Done."

MatrixMult: MatrixMultC MatrixMultCpp
Concat: ConcatC ConcatCpp
Regexp: RegexpC RegexpCpp

MatrixMultC: D=src/c
MatrixMultC: MatrixMult1C MatrixMult2C MatrixMult3C

ConcatC: D=src/c
ConcatC: Concat1C Concat2C Concat3C

RegexpC: D=src/c
RegexpC: Regexp1C Regexp2C Regexp3C


MatrixMultCpp: D=src/cpp
MatrixMultCpp: MatrixMult1Cpp MatrixMult2Cpp MatrixMult3Cpp

ConcatCpp: D=src/cpp
ConcatCpp: Concat1Cpp Concat2Cpp Concat3Cpp

RegexpCpp: D=src/cpp
RegexpCpp: Regexp1Cpp Regexp2Cpp Regexp3Cpp


include src/c/Makefile
include src/cpp/Makefile

