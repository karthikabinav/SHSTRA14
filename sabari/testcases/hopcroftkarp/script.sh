#!/bin/bash

for i in {0..14}
do
    ./a.out < karp_in_$i > karp_out_$i
    echo $i" done"
done
