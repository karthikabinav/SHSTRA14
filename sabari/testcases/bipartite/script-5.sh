#!/bin/bash

for i in {0..6}
do
    ./a.out < bipartite_in_$i > bipartite_out_$i
    echo $i" done"
done
