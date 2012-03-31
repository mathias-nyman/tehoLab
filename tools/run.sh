#!/bin/bash

case "$1" in
    Concat)
        data_dir=concat
        ;;
    MatrixMult)
        data_dir=matrix_mult
        ;;
    Regexp)
        data_dir=regexp
        ;;
esac

case "$2" in
    C)
        for prog in "../src/c/$11C" "../src/c/$13C"
        do
            time -p for ((i=0; i<$3; i++))
        do
            $prog ../data/$data_dir/data.txt $4 $5 $6
        done
        done
        ;;
    C++)
        for prog in "../src/cpp/$11Cpp" "../src/cpp/$12Cpp" "../src/cpp/$13Cpp"
        do
            time -p for ((i=0; i<$3; i++))
        do
            $prog ../data/$data_dir/data.txt $4 $5 $6
        done
        done
        ;;
    Java)
        for prog in "$11" "$12" "$13"
        do
            time -p for ((i=0; i<$3; i++))
        do
            java -d64 -cp ../src/java/ $prog ../data/$data_dir/data.txt $4 $5 $6
        done
        done
        ;;
    Python)
        for prog in "../src/python/$11.py" "../src/python/$12.py"
        do
            time -p for ((i=0; i<$3; i++))
        do
            python $prog ../data/$data_dir/data.txt $4 $5 $6
        done
        done
        ;;
    Perl)
        for prog in "../src/perl/$11.pl" "../src/perl/$12.pl"
        do
            time -p for ((i=0; i<$3; i++))
        do
            perl $prog ../data/$data_dir/data.txt $4 $5 $6
        done
        done
        ;;
esac