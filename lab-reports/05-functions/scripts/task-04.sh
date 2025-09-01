#!/bin/bash

read number
length=${#number}

armstrong_number() {
	sum=0
	for ((i = 0; i < length; i++)); do
		digit=${number:$i:1}
		power=1
		for ((x = 0; x < length; x++)); do
			power=$(($power * $digit))
		done
		sum=$(($sum + $power))
	done

	if [ $number -eq $sum ]; then
		echo "Armstrong Number"
	else
		echo "Not Armstrong Number"
	fi
}

armstrong_number
