#!/bin/bash
read x

lx=${x,,}
len=${#x}
y=0

for ((i = 0; i < len; i++)); do
	z=${lx:$i:1}
	if [ $z == "a" ] || [ $z == "e" ] || [ $z == "i" ] || [ $z == "o" ] || [ $z == "u" ]; then
		y=$((y + 1))
	fi
done

echo $y
