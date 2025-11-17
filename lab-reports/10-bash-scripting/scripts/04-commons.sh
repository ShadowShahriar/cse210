#!/bin/bash
read s1
read s2

common=""
for ((i = 0; i < ${#s1}; i++)); do
	ch="${s1:$i:1}"
	if [[ "$s2" == *"$ch"* ]] && [[ "$common" != *"$ch"* ]]; then
		common+="$ch"
	fi
done

echo "$common"
