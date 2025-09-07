#!/bin/bash
x=0
r=0
read x
r=$((x % 2))

if [ $r == 0 ]; then
	echo YES
else
	echo NO
fi
