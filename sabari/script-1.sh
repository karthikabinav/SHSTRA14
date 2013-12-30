#!/bin/bash

for i in {0..6}
do
    ./a.out < a_powb_in_$i > a_powb_out_$i
done
