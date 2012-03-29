#!/bin/bash

case "$1" in
    C)
        for prog in ../src/c/Concat1C ../src/c/Concat3C
        do
            time -p for ((i=0; i<$2; i++))
        do
            $prog ../data/concat/data.txt $3
        done
        done
        ;;
    C++)
        for prog in ../src/cpp/Concat1Cpp ../src/cpp/Concat2Cpp ../src/cpp/Concat3Cpp
        do
            time -p for ((i=0; i<$2; i++))
        do
            $prog ../data/concat/data.txt $3
        done
        done
        ;;
    Java)
        for prog in Concat1 Concat2 Concat3
        do
            time -p for ((i=0; i<$2; i++))
        do
            java -d64 -cp ../src/java/ $prog ../data/concat/data.txt $3
        done
        done
        ;;
    Python)
        for prog in ../src/python/Concat1.py ../src/python/Concat3.py
        do
            time -p for ((i=0; i<$2; i++))
        do
            python $prog ../data/concat/data.txt $3
        done
        done
        ;;
    Perl)
        for prog in ../src/perl/Concat1.pl ../src/perl/Concat3.pl
        do
            time -p for ((i=0; i<$2; i++))
        do
            perl $prog ../data/concat/data.txt $3
        done
        done
        ;;
esac