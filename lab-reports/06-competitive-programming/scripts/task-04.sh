#!/bin/bash
read -p "no. test cases: " n
echo ""
for ((i = 0; i < n; i++)); do
	a=0
	b=0
	x=0
	r=-1
	read -p "a: " a
	read -p "b: " b
	while [ $(($r != 0)) -ne 0 ]; do
		a=$(($a + 1))
		r=$(($a % $b))
		x=$(($x + 1))
	done
	echo "minimum number of moves:" $x
	echo ""
done
