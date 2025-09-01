#!/bin/bash

n=0
read -p "Enter the value of n= " n

real_sum=0
expected_sum=0
check_sum() {
	expected_sum=$(((n - 1) * (n) / 2))
	for ((i = 0; i < n - 1; i++)); do
		read -p "Enter number= " x
		real_sum=$(($real_sum + $x))
	done
	echo "Missing number=" $(($expected_sum - $real_sum))
}

check_sum
