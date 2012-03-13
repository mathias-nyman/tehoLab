.PHONY: all data

MATRIX_MULT_DATA:=data/matrix_mult/data.txt
CONCAT_DATA:=data/concat/data.txt
REGEXP_DATA:=data/regexp/data.txt

TIME:=time

all: MatrixMult Concat Regexp
	@echo "Done."

data:
	@wget http://dl.dropbox.com/u/31514170/data.txt -O $(MATRIX_MULT_DATA)

MatrixMult: MatrixMultC MatrixMultCpp MatrixMultJava MatrixMultPython MatrixMultPerl
Concat: ConcatC ConcatCpp ConcatJava ConcatPython ConcatPerl
Regexp: RegexpC RegexpCpp RegexpJava RegexpPython RegexpPerl

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


MatrixMultJava: D=src/java
MatrixMultJava: MatrixMult1Java MatrixMult2Java MatrixMult3Java

ConcatJava: D=src/java
ConcatJava: Concat1Java Concat2Java Concat3Java

RegexpJava: D=src/java
RegexpJava: Regexp1Java Regexp2Java Regexp3Java


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
include src/java/Makefile
include src/python/Makefile
include src/perl/Makefile

