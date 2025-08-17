#!/bin/bash
read -p "Input value 1: " a
read -p "Input value 2: " b
echo "a + b = " $(($a + $b))
echo "a - b = " $(($a - $b))
echo "a * b = " $(($a * $b))
echo "a / b = " $(($a / $b))
