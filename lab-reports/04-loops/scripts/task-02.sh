#!/bin/bash
read n

t1=0
t2=1
tn=$(($t1 + $t2))

echo -n "$t2 "

for ((i = 3; i <= n + 1; i++)); do
	echo -n "$tn "
	t1=$t2
	t2=$tn
	tn=$(($t1 + $t2))
done
echo ""
