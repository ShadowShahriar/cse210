#!/bin/bash
echo "Hello World"
a=10
c=25
d=$(($a+$c))
echo $d

b=Hello
read b
echo $b

read -p "What is your name? " x
echo $x

arr=("apple" "banana" "orange" "kiwi")
echo ${arr[0]}

if [ $a -gt 5 ]; then
echo "True"
#elif
else
echo "False"
fi
