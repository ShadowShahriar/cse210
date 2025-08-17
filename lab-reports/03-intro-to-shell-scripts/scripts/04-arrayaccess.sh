#!/bin/bash
array=("Shayan Shahriar" 21 "Dhaka")
read -p "Please enter an index value: " index
echo ${array[$index]}
