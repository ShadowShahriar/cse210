#!/bin/bash
read n

for ((i = 1; i <= n; i++)); do
	for ((j = 1; j <= i; j++)); do
		echo -n "*"
	done
	echo ""
done

for ((i = n - 1; i >= 0; i--)); do
	for ((j = 1; j <= i; j++)); do
		echo -n "*"
	done
	echo ""
done
