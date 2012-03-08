D :=.

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allCpp
.PHONY: MatrixMult1Cpp MatrixMult2Cpp MatrixMult3Cpp
.PHONY: Concat1Cpp Concat2Cpp Concat3Cpp
.PHONY: Regexp1Cpp Regexp2Cpp Regexp3Cpp

allCpp: MatrixMult1Cpp MatrixMult2Cpp MatrixMult3Cpp Concat1Cpp Concat2Cpp Concat3Cpp Regexp1Cpp Regexp2Cpp Regexp3Cpp

MatrixMult1Cpp:
	@g++ -o $(D)/$@ $(D)/MatrixMult1.cpp
	$(D)/$@

MatrixMult2Cpp:
	@g++ -o $(D)/$@ $(D)/MatrixMult2.cpp
	$(D)/$@

MatrixMult3Cpp:
	@g++ -o $(D)/$@ $(D)/MatrixMult3.cpp
	$(D)/$@


Concat1Cpp:
	@g++ -o $(D)/$@ $(D)/Concat1.cpp
	$(D)/$@ $(CONCAT_DATA)

Concat2Cpp:
	@g++ -o $(D)/$@ $(D)/Concat2.cpp
	$(D)/$@ $(CONCAT_DATA)

Concat3Cpp:
	@g++ -o $(D)/$@ $(D)/Concat3.cpp
	$(D)/$@ $(CONCAT_DATA)


Regexp1Cpp:
	@g++ -o $(D)/$@ $(D)/Regexp1.cpp
	$(D)/$@

Regexp2Cpp:
	@g++ -o $(D)/$@ $(D)/Regexp2.cpp
	$(D)/$@

Regexp3Cpp:
	@g++ -o $(D)/$@ $(D)/Regexp3.cpp
	$(D)/$@

