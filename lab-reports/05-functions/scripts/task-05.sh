#!/bin/bash
read -p "x = " x
read -p "y = " y

calc_gcd() {
	local a=$1
	local b=$2

	while [ $b -ne 0 ]; do
		r=$(($a % $b))
		a=$b
		b=$r
	done
	echo "gcd(x, y) =" $a
}

calc_gcd $x $y
