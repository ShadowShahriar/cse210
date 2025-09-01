#!/bin/bash

reversed=""
reverse_string() {
	str=$1
	rstr=$(echo "$str" | rev)
	reversed=$rstr
}

main() {
	read str
	reverse_string $str
	if [ $str == $reversed ]; then
		echo "Palindrome"
	else
		echo "Not Palindrome"
	fi
}

main
