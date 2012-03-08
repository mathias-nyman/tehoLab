D :=.

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
	$(JAVA) -cp $(D) MatrixMult1

MatrixMult2Java:
	@javac $(D)/MatrixMult2.java
	$(JAVA) -cp $(D) MatrixMult2

MatrixMult3Java:
	@javac $(D)/MatrixMult3.java
	$(JAVA) -cp $(D) MatrixMult3


Concat1Java:
	@javac $(D)/Concat1.java
	$(JAVA) -cp $(D) Concat1 $(CONCAT_DATA)

Concat2Java:
	@javac $(D)/Concat2.java
	$(JAVA) -cp $(D) Concat2 $(CONCAT_DATA)

Concat3Java:
	@javac $(D)/Concat3.java
	$(JAVA) -cp $(D) Concat3 $(CONCAT_DATA)


Regexp1Java:
	@javac $(D)/Regexp1.java
	$(JAVA) -cp $(D) Regexp1

Regexp2Java:
	@javac $(D)/Regexp2.java
	$(JAVA) -cp $(D) Regexp2

Regexp3Java:
	@javac $(D)/Regexp3.java
	$(JAVA) -cp $(D) Regexp3

