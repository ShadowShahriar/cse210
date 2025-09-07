#!/bin/bash
read filename
while IFS= read -r line; do
	str=$(echo "$line")
	echo $str | rev
done <$filename
