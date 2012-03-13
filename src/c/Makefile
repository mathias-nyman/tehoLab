D :=.
TIME ?= time

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allC
.PHONY: MatrixMult1C MatrixMult2C MatrixMult3C
.PHONY: Concat1C Concat2C Concat3C
.PHONY: Regexp1C Regexp2C Regexp3C

allC: MatrixMult1C MatrixMult2C MatrixMult3C Concat1C Concat2C Concat3C Regexp1C Regexp2C Regexp3C

MatrixMult1C:
	@gcc -o $(D)/$@ $(D)/MatrixMult1.c
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100 --float

MatrixMult2C:
	@gcc -o $(D)/$@ $(D)/MatrixMult2.c
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100 --float

MatrixMult3C:
	@gcc -o $(D)/$@ $(D)/MatrixMult3.c
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100
	$(TIME) $(D)/$@ $(MATRIX_MULT_DATA) 100 --float


Concat1C:
	@gcc -o $(D)/$@ $(D)/Concat1.c
	$(TIME) $(D)/$@ $(CONCAT_DATA)

Concat2C:
	@gcc -o $(D)/$@ $(D)/Concat2.c
	$(TIME) $(D)/$@ $(CONCAT_DATA)

Concat3C:
	@gcc -o $(D)/$@ $(D)/Concat3.c
	$(TIME) $(D)/$@ $(CONCAT_DATA)


Regexp1C:
	@gcc -o $(D)/$@ $(D)/Regexp1.c
	$(TIME) $(D)/$@ $(REGEXP_DATA)
	$(TIME) $(D)/$@ $(REGEXP_DATA) --with-or-operator

Regexp2C:
	@gcc -o $(D)/$@ $(D)/Regexp2.c
	$(TIME) $(D)/$@ $(REGEXP_DATA)
	$(TIME) $(D)/$@ $(REGEXP_DATA) --with-or-operator

Regexp3C:
	@gcc -o $(D)/$@ $(D)/Regexp3.c
	$(TIME) $(D)/$@ $(REGEXP_DATA)
	$(TIME) $(D)/$@ $(REGEXP_DATA) --with-or-operator

