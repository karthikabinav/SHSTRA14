#!/bin/bash

for i in {0..6}
do
    ./a.out < stringdp_in_$i > stringdp_out_$i
done
