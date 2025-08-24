#!/bin/bash
read year

divby4=$((year % 4))
divby400=$((year % 400))
divby100=$((year % 100))

y1=$((year + 1))
y2=$((year - 1))

counter=1
while [ $counter -le 4 ]; do
	divby4=$((y1 % 4))
	divby400=$((y1 % 400))
	divby100=$((y1 % 100))
	if ([ $divby4 -eq 0 ] || [ $divby400 -eq 0 ]) && [ $divby100 != 0 ]; then
		# echo $y1
		break
	fi
	((y1++))
	((counter++))
done

counter=4
while [ $counter -ge 0 ]; do
	divby4=$((y2 % 4))
	divby400=$((y2 % 400))
	divby100=$((y2 % 100))
	if ([ $divby4 -eq 0 ] || [ $divby400 -eq 0 ]) && [ $divby100 != 0 ]; then
		# echo $y2
		break
	fi
	((y2--))
	((counter--))
done

forwards=$((y1 - year))
backwards=$((year - y2))

echo -n "Nearest leap year: "
if [ $backwards -lt $forwards ]; then
	echo $y2
else
	echo $y1
fi
