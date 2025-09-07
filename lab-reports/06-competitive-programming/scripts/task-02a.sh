#!/bin/bash
read filename
echo $(cat $filename | rev)
