D :=.
TIME ?= time

MATRIX_MULT_DATA ?= ../../data/matrix_mult/data.txt
CONCAT_DATA ?= ../../data/concat/data.txt
REGEXP_DATA ?= ../../data/regexp/data.txt

JAVA:=java -d64

.PHONY: allJava
.PHONY: MatrixMult1Java MatrixMult2Java MatrixMult3Java
.PHONY: Concat1Java Concat2Java Concat3Java
.PHONY: Regexp1Java Regexp2Java Regexp3Java

allJava: MatrixMult1Java MatrixMult2Java MatrixMult3Java Concat1Java Concat2Java Concat3Java Regexp1Java Regexp2Java Regexp3Java

MatrixMult1Java:
	@javac $(D)/MatrixMult1.java
	$(TIME) $(JAVA) -cp $(D) MatrixMult1 $(MATRIX_MULT_DATA) 100 --dry-run
	$(TIME) $(JAVA) -cp $(D) MatrixMult1 $(MATRIX_MULT_DATA) 100
	$(TIME) $(JAVA) -cp $(D) MatrixMult1 $(MATRIX_MULT_DATA) 100 --float --dry-run
	$(TIME) $(JAVA) -cp $(D) MatrixMult1 $(MATRIX_MULT_DATA) 100 --float

MatrixMult2Java:
	@javac $(D)/MatrixMult2.java
	$(TIME) $(JAVA) -cp $(D) MatrixMult2 $(MATRIX_MULT_DATA) 100 --dry-run
	$(TIME) $(JAVA) -cp $(D) MatrixMult2 $(MATRIX_MULT_DATA) 100
	$(TIME) $(JAVA) -cp $(D) MatrixMult2 $(MATRIX_MULT_DATA) 100 --float --dry-run
	$(TIME) $(JAVA) -cp $(D) MatrixMult2 $(MATRIX_MULT_DATA) 100 --float

MatrixMult3Java:
	@javac $(D)/MatrixMult3.java
	$(TIME) $(JAVA) -cp $(D) MatrixMult3 $(MATRIX_MULT_DATA) 100
	$(TIME) $(JAVA) -cp $(D) MatrixMult3 $(MATRIX_MULT_DATA) 100 --float


Concat1Java:
	@javac $(D)/Concat1.java
	$(TIME) $(JAVA) -cp $(D) Concat1 $(CONCAT_DATA) --dry-run
	$(TIME) $(JAVA) -cp $(D) Concat1 $(CONCAT_DATA)

Concat2Java:
	@javac $(D)/Concat2.java
	$(TIME) $(JAVA) -cp $(D) Concat2 $(CONCAT_DATA) --dry-run
	$(TIME) $(JAVA) -cp $(D) Concat2 $(CONCAT_DATA)

Concat3Java:
	@javac $(D)/Concat3.java
	$(TIME) $(JAVA) -cp $(D) Concat3 $(CONCAT_DATA)


Regexp1Java:
	@javac $(D)/Regexp1.java
	$(TIME) $(JAVA) -cp $(D) Regexp1 $(REGEXP_DATA) --dry-run
	$(TIME) $(JAVA) -cp $(D) Regexp1 $(REGEXP_DATA)
	$(TIME) $(JAVA) -cp $(D) Regexp1 $(REGEXP_DATA) --with-or-operator --dry-run
	$(TIME) $(JAVA) -cp $(D) Regexp1 $(REGEXP_DATA) --with-or-operator

Regexp2Java:
	@javac $(D)/Regexp2.java
	$(TIME) $(JAVA) -cp $(D) Regexp2 $(REGEXP_DATA) --dry-run
	$(TIME) $(JAVA) -cp $(D) Regexp2 $(REGEXP_DATA)
	$(TIME) $(JAVA) -cp $(D) Regexp2 $(REGEXP_DATA) --with-or-operator --dry-run
	$(TIME) $(JAVA) -cp $(D) Regexp2 $(REGEXP_DATA) --with-or-operator

Regexp3Java:
	@javac $(D)/Regexp3.java
	$(TIME) $(JAVA) -cp $(D) Regexp3 $(REGEXP_DATA)
	$(TIME) $(JAVA) -cp $(D) Regexp3 $(REGEXP_DATA) --with-or-operator

