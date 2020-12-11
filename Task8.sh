#!/bin/bash
#COSC 350
#Keith Flagg

x=$1 

if [ $# -eq 0 ]
then
  echo "No parameters, bye!"
  exit 1
fi

while [ $x -gt 0 ]
do
    rem=$(( $x % 10 )) 
    x=$(( $x / 10 ))
    sum=$(( $sum + $rem ))
done

echo  "sum of digits: $sum"
exit 0