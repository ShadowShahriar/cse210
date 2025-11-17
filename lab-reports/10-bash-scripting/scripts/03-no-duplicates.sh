#!/bin/bash
read numbers

unique=""
for n in $numbers; do
	if ! echo " $unique " | grep -q " $n "; then
		unique+="$n "
	fi
done

echo "$unique"
