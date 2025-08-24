#!/bin/bash
read n

if [[ $n -le 1 ]]; then
	echo "$n is not a prime number."
	exit 0
fi

is_prime=true
for ((i = 2; i <= $n / 2; i++)); do
	if [ $((n % i)) -eq 0 ]; then
		is_prime=false
		break
	fi
done

if $is_prime; then
	echo "$n is a prime number."
else
	echo "$n is not a prime number."
fi
