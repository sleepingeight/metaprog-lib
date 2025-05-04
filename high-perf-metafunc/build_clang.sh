#!/bin/bash

file=$1;
compilations=$2;
algo=$3
input=$4

for ((i=0;i<compilations;i++))
do
    clang++ -O2 -std=c++20 -ftemplate-depth=50000 $file -DALGO=$algo -DINPUT=$input
done
