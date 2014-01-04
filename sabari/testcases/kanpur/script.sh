#!/bin/bash

for i in {0..7}
do
    ./a.out < kanpur_in_$i > kanpur_out_$i
    echo $i" done"
done
