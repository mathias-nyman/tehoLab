#!/bin/bash

if [ $# -lt 4 ]
then
    echo -e "Usage: $0 DIM_BEGIN DIM_END DIM_INCR REPEAT_CONST [--float]"
    exit 0
fi

echo -e "#Dim\tC1\tC3\tC++1\tC++2\tC++3\tJava1\tJava2\tJava3\tPython1\tPython2\tPerl1\tPerl2"

const=$4

for ((dim=$1; dim<=$2; dim=$dim+$3))
do
    line="$dim"
    repeats=$const/$dim

    for lang in C C++ Java Python Perl
    do
        declare -a ordinary
        for res in $(./run.sh MatrixMult $lang $repeats $dim $5 3>&1 1>&2 2>&3 | sed -e 's/^[a-zA-Z ]*//' -n -e  2p -e 5p -e 8p)
        do
            ordinary+=("$res")
        done
        
        declare -a dry_run
        for res in $(./run.sh MatrixMult $lang $repeats $dim $5 --dry-run 3>&1 1>&2 2>&3 | sed -e 's/^[a-zA-Z ]*//' -n -e  2p -e 5p -e 8p)
        do
            dry_run+=("$res")
        done
        
        for ((i=0;i<${#ordinary[@]};i++))
        do
            eq="scale=2; (${ordinary[$i]}-${dry_run[$i]})/($repeats/10.0);"
            value=$(bc <<< $eq)
            line="$line\t$value"
        done
        unset ordinary
        unset dry_run
    done
    echo -e $line
done