#!/bin/bash
read year

divby4=$((year % 4))
divby400=$((year % 400))
divby100=$((year % 100))

if ([ $divby4 -eq 0 ] || [ $divby400 -eq 0 ]) && [ divby100 != 0 ]; then
	echo $year "is a leap year."
else
	echo $year "is not a leap year."
fi
