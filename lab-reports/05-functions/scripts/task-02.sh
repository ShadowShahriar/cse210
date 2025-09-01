#!/bin/bash

m=1
fact() {
	local f=$1
	if [ $1 -eq 1 ]; then
		echo $m
	else
		n=$(($1 - 1))
		m=$(($f * $m))
		fact $n
	fi
}

read n
fact $n
