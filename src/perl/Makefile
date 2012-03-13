D :=.
TIME ?= time

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allPerl
.PHONY: MatrixMult1Perl MatrixMult2Perl MatrixMult3Perl
.PHONY: Concat1Perl Concat2Perl Concat3Perl
.PHONY: Regexp1Perl Regexp2Perl Regexp3Perl

allPerl: MatrixMult1Perl MatrixMult2Perl MatrixMult3Perl Concat1Perl Concat2Perl Concat3Perl Regexp1Perl Regexp2Perl Regexp3Perl

MatrixMult1Perl:
	$(TIME) perl $(D)/MatrixMult1.pl $(MATRIX_MULT_DATA) 100
	$(TIME) perl $(D)/MatrixMult1.pl $(MATRIX_MULT_DATA) 100 --float

MatrixMult2Perl:
	$(TIME) perl $(D)/MatrixMult2.pl $(MATRIX_MULT_DATA) 100
	$(TIME) perl $(D)/MatrixMult2.pl $(MATRIX_MULT_DATA) 100 --float

MatrixMult3Perl:
	$(TIME) perl $(D)/MatrixMult3.pl $(MATRIX_MULT_DATA) 100
	$(TIME) perl $(D)/MatrixMult3.pl $(MATRIX_MULT_DATA) 100 --float


Concat1Perl:
	$(TIME) perl $(D)/Concat1.pl $(CONCAT_DATA)

Concat2Perl:
	$(TIME) perl $(D)/Concat2.pl $(CONCAT_DATA)

Concat3Perl:
	$(TIME) perl $(D)/Concat3.pl $(CONCAT_DATA)


Regexp1Perl:
	$(TIME) perl $(D)/Regexp1.pl $(REGEXP_DATA)
	$(TIME) perl $(D)/Regexp1.pl $(REGEXP_DATA) --with-or-operator

Regexp2Perl:
	$(TIME) perl $(D)/Regexp2.pl $(REGEXP_DATA)
	$(TIME) perl $(D)/Regexp2.pl $(REGEXP_DATA) --with-or-operator

Regexp3Perl:
	$(TIME) perl $(D)/Regexp3.pl $(REGEXP_DATA)
	$(TIME) perl $(D)/Regexp3.pl $(REGEXP_DATA) --with-or-operator

