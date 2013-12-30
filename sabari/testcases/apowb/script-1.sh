#!/bin/bash

for i in {0..6}
do
    ./a.out < apowb_in_$i > apowb_out_$i
done
