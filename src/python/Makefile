D :=.

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

.PHONY: allPython
.PHONY: MatrixMult1Python MatrixMult2Python MatrixMult3Python
.PHONY: Concat1Python Concat2Python Concat3Python
.PHONY: Regexp1Python Regexp2Python Regexp3Python

allPython: MatrixMult1Python MatrixMult2Python MatrixMult3Python Concat1Python Concat2Python Concat3Python Regexp1Python Regexp2Python Regexp3Python

MatrixMult1Python:
	python $(D)/MatrixMult1.py

MatrixMult2Python:
	python $(D)/MatrixMult2.py

MatrixMult3Python:
	python $(D)/MatrixMult3.py


Concat1Python:
	python $(D)/Concat1.py

Concat2Python:
	python $(D)/Concat2.py $(CONCAT_DATA)

Concat3Python:
	python $(D)/Concat3.py


Regexp1Python:
	python $(D)/Regexp1.py

Regexp2Python:
	python $(D)/Regexp2.py $(REGEXP_DATA)
	python $(D)/Regexp2.py $(REGEXP_DATA) --with-or-operator

Regexp3Python:
	python $(D)/Regexp3.py

