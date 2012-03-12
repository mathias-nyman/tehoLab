D :=.

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allCpp
.PHONY: MatrixMult1Cpp MatrixMult2Cpp MatrixMult3Cpp
.PHONY: Concat1Cpp Concat2Cpp Concat3Cpp
.PHONY: Regexp1Cpp Regexp2Cpp Regexp3Cpp

CXX:=g++ -std=c++0x

allCpp: MatrixMult1Cpp MatrixMult2Cpp MatrixMult3Cpp Concat1Cpp Concat2Cpp Concat3Cpp Regexp1Cpp Regexp2Cpp Regexp3Cpp

MatrixMult1Cpp:
	@$(CXX) -o $(D)/$@ $(D)/MatrixMult1.cpp
	$(D)/$@ $(MATRIX_MULT_DATA) 100
	$(D)/$@ $(MATRIX_MULT_DATA) 100 --float

MatrixMult2Cpp:
	@$(CXX) -o $(D)/$@ $(D)/MatrixMult2.cpp
	$(D)/$@ $(MATRIX_MULT_DATA) 100
	$(D)/$@ $(MATRIX_MULT_DATA) 100 --float

MatrixMult3Cpp:
	@$(CXX) -o $(D)/$@ $(D)/MatrixMult3.cpp
	$(D)/$@ $(MATRIX_MULT_DATA) 100
	$(D)/$@ $(MATRIX_MULT_DATA) 100 --float


Concat1Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Concat1.cpp
	$(D)/$@ $(CONCAT_DATA)

Concat2Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Concat2.cpp
	$(D)/$@ $(CONCAT_DATA)

Concat3Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Concat3.cpp
	$(D)/$@ $(CONCAT_DATA)


Regexp1Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Regexp1.cpp
	$(D)/$@ $(REGEXP_DATA)
	$(D)/$@ $(REGEXP_DATA) --with-or-operator

Regexp2Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Regexp2.cpp
	$(D)/$@ $(REGEXP_DATA)
	$(D)/$@ $(REGEXP_DATA) --with-or-operator

Regexp3Cpp:
	@$(CXX) -o $(D)/$@ $(D)/Regexp3.cpp
	$(D)/$@ $(REGEXP_DATA)
	$(D)/$@ $(REGEXP_DATA) --with-or-operator

