#!/bin/bash

for i in {0..6}
do
    ./a.out < nash_in_$i > nash_out_$i
done
