#!/bin/bash
read x
read y

if ([ $x -le 0 ] || [ $y -le $x ]); then
	echo "Range error"
	exit 0
fi

for ((i = x; i <= y; i++)); do
	if [ $i == 2 ] || [ $i == 3 ]; then
		echo -n "$i "
	fi
	prime=true
	for ((j = 2; j <= $i / 2; j++)); do
		if [ $((i % j)) -eq 0 ]; then
			prime=false
			break
		fi
	done
	if $prime; then
		echo -n "$i "
	fi
done

echo ""
