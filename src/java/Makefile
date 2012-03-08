D :=.

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
	$(JAVA) -cp $(D) Concat1

Concat2Java:
	@javac $(D)/Concat2.java
	$(JAVA) -cp $(D) Concat2

Concat3Java:
	@javac $(D)/Concat3.java
	$(JAVA) -cp $(D) Concat3


Regexp1Java:
	@javac $(D)/Regexp1.java
	$(JAVA) -cp $(D) Regexp1

Regexp2Java:
	@javac $(D)/Regexp2.java
	$(JAVA) -cp $(D) Regexp2

Regexp3Java:
	@javac $(D)/Regexp3.java
	$(JAVA) -cp $(D) Regexp3

