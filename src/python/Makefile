D :=.
TIME ?= time

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allPython
.PHONY: MatrixMult1Python MatrixMult2Python MatrixMult3Python
.PHONY: Concat1Python Concat2Python Concat3Python
.PHONY: Regexp1Python Regexp2Python Regexp3Python

allPython: MatrixMult1Python MatrixMult2Python MatrixMult3Python Concat1Python Concat2Python Concat3Python Regexp1Python Regexp2Python Regexp3Python

MatrixMult1Python:
	$(TIME) python $(D)/MatrixMult1.py $(MATRIX_MULT_DATA) 100 --dry-run
	$(TIME) python $(D)/MatrixMult1.py $(MATRIX_MULT_DATA) 100
	$(TIME) python $(D)/MatrixMult1.py $(MATRIX_MULT_DATA) 100 --float --dry-run
	$(TIME) python $(D)/MatrixMult1.py $(MATRIX_MULT_DATA) 100 --float

MatrixMult2Python:
	$(TIME) python $(D)/MatrixMult2.py $(MATRIX_MULT_DATA) 100 --dry-run
	$(TIME) python $(D)/MatrixMult2.py $(MATRIX_MULT_DATA) 100
	$(TIME) python $(D)/MatrixMult2.py $(MATRIX_MULT_DATA) 100 --float --dry-run
	$(TIME) python $(D)/MatrixMult2.py $(MATRIX_MULT_DATA) 100 --float

MatrixMult3Python:
	$(TIME) python $(D)/MatrixMult3.py $(MATRIX_MULT_DATA) 100
	$(TIME) python $(D)/MatrixMult3.py $(MATRIX_MULT_DATA) 100 --float


Concat1Python:
	$(TIME) python $(D)/Concat1.py $(CONCAT_DATA) --dry-run
	$(TIME) python $(D)/Concat1.py $(CONCAT_DATA)

Concat2Python:
	$(TIME) python $(D)/Concat2.py $(CONCAT_DATA) --dry-run
	$(TIME) python $(D)/Concat2.py $(CONCAT_DATA)

Concat3Python:
	$(TIME) python $(D)/Concat3.py $(CONCAT_DATA)


Regexp1Python:
	$(TIME) python $(D)/Regexp1.py $(REGEXP_DATA) --dry-run
	$(TIME) python $(D)/Regexp1.py $(REGEXP_DATA)
	$(TIME) python $(D)/Regexp1.py $(REGEXP_DATA) --with-or-operator --dry-run
	$(TIME) python $(D)/Regexp1.py $(REGEXP_DATA) --with-or-operator

Regexp2Python:
	$(TIME) python $(D)/Regexp2.py $(REGEXP_DATA) --dry-run
	$(TIME) python $(D)/Regexp2.py $(REGEXP_DATA)
	$(TIME) python $(D)/Regexp2.py $(REGEXP_DATA) --with-or-operator --dry-run
	$(TIME) python $(D)/Regexp2.py $(REGEXP_DATA) --with-or-operator

Regexp3Python:
	$(TIME) python $(D)/Regexp3.py $(REGEXP_DATA)
	$(TIME) python $(D)/Regexp3.py $(REGEXP_DATA) --with-or-operator

