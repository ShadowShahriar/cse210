#!/bin/bash
read -p "Please enter your age: " age
echo "Age:" $age

if [ $age -ge 18 ]; then
echo "Adult"
else
echo "Minor"
fi
