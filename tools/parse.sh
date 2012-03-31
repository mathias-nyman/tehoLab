#!/bin/bash

if [ $# -lt 2 ]
then
    echo -e "Usage: $0 PROG=[Concat|Regexp] REPETITIONS [--with-or-operator]"
    exit 0
fi

echo -e "#Index\tProg1\tProg2\tProg3\tLang"
n=1
for lang in C C++ Java Python Perl
do
    line="$n"
    declare -a ordinary
    for res in $(./run.sh $1 $lang $2 $3 3>&1 1>&2 2>&3 | sed -e 's/^[a-zA-Z ]*//' -n -e  2p -e 5p -e 8p)
    do
        ordinary+=("$res")
    done

    declare -a dry_run
    for res in $(./run.sh $1 $lang $2 $3 --dry-run 3>&1 1>&2 2>&3 | sed -e 's/^[a-zA-Z ]*//' -n -e  2p -e 5p -e 8p)
    do
        dry_run+=("$res")
    done

    for ((i=0;i<${#ordinary[@]};i++))
    do
        if [ ${#ordinary[@]} -lt 3 ] && [ $lang = C ] && [ $i -eq 1 ]
        then
            line="$line\t?"
        fi
        eq="scale=2; ${ordinary[$i]}-${dry_run[$i]};"
        value=$(bc <<< $eq)
        line="$line\t$value"
    done
    if [ ${#ordinary[@]} -lt 3 ]  && [ $lang != C ]
    then
        line="$line\t?"
    fi
    line="$line\t$lang"
    echo -e $line
    unset ordinary
    unset dry_run
    let n++
done