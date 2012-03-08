.PHONY: all

all: MatrixMult Concat Regexp
	@echo "Done."

MatrixMult: MatrixMultC MatrixMultCpp MatrixMultPython MatrixMultPerl
Concat: ConcatC ConcatCpp ConcatPython ConcatPerl
Regexp: RegexpC RegexpCpp RegexpPython RegexpPerl

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


MatrixMultPython: D=src/python
MatrixMultPython: MatrixMult1Python MatrixMult2Python MatrixMult3Python

ConcatPython: D=src/python
ConcatPython: Concat1Python Concat2Python Concat3Python

RegexpPython: D=src/python
RegexpPython: Regexp1Python Regexp2Python Regexp3Python


MatrixMultPerl: D=src/perl
MatrixMultPerl: MatrixMult1Perl MatrixMult2Perl MatrixMult3Perl

ConcatPerl: D=src/perl
ConcatPerl: Concat1Perl Concat2Perl Concat3Perl

RegexpPerl: D=src/perl
RegexpPerl: Regexp1Perl Regexp2Perl Regexp3Perl


include src/c/Makefile
include src/cpp/Makefile
include src/python/Makefile
include src/perl/Makefile

