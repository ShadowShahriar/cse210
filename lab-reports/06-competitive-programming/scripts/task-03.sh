#!/bin/bash
sum=0
read n
for ((i = 1; i <= n; i++)); do
	sum=$(($sum + $i * (-1 ** i)))
done
echo $sum
