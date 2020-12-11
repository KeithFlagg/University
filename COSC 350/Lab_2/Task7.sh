#!/bin/bash
#COSC 350
#Keith Flagg
par=$1
fact=1

if [ $# -eq 0 ]
then
  echo "There are no parameters, bye!"
  exit 1
fi

while(($par>1))
do
  fact=$((fact * $par))
  par=$(($par - 1))
done

echo "n!: $fact"

exit 0;
