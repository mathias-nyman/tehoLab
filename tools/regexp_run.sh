#!/bin/bash

case "$1" in
    C)
        for prog in ../src/c/Regexp1C ../src/c/Regexp3C
        do
            time -p for ((i=0; i<$2; i++))
        do
            $prog ../data/concat/data.txt $3 $4
        done
        done
        ;;
    C++)
        for prog in ../src/cpp/Regexp1Cpp ../src/cpp/Regexp2Cpp ../src/cpp/Regexp3Cpp
        do
            time -p for ((i=0; i<$2; i++))
        do
            $prog ../data/concat/data.txt $3 $4
        done
        done
        ;;
    Java)
        for prog in Regexp1 Regexp2 Regexp3
        do
            time -p for ((i=0; i<$2; i++))
        do
            java -d64 -cp ../src/java/ $prog ../data/concat/data.txt $3 $4
        done
        done
        ;;
    Python)
        for prog in ../src/python/Regexp1.py ../src/python/Regexp3.py
        do
            time -p for ((i=0; i<$2; i++))
        do
            python $prog ../data/concat/data.txt $3 $4
        done
        done
        ;;
    Perl)
        for prog in ../src/perl/Regexp1.pl ../src/perl/Regexp3.pl
        do
            time -p for ((i=0; i<$2; i++))
        do
            perl $prog ../data/concat/data.txt $3 $4
        done
        done
        ;;
esac