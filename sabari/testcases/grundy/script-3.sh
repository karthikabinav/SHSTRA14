#!/bin/bash

for i in {0..6}
do
    ./a.out < grundy_in_$i > grundy_out_$i
    echo $i."done"
done
