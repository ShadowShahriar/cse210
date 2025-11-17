#!/bin/bash
read n

for ((i = 1; i <= n; i++)); do
	if ((i % 15 == 0)); then
		echo "FizzBuzz"
	elif ((i % 3 == 0)); then
		echo "Fizz"
	elif ((i % 5 == 0)); then
		echo "Buzz"
	else
		echo "$i"
	fi
done
