#!/bin/bash
#COSC 350
#Keith Flagg
echo -n  "Enter a number between 5 to 9: "
read x
if [ $x -lt 5 ]; then
    echo "Please try again (integer 5-9)"
    exit -1
fi

if [ $x -gt 9 ]; then
    echo "Try again with a number between 5 to 9"
    exit -1
fi


for (( i=0; i<=$x; i++ ))
do
  
  spaces=$(( 9-$i ))
  for (( j=0; j<$spaces; j++ ))
  do
    printf " "
  done
  for (( j=0; j<$i; j++ ))
  do
    printf "$i "
  done
  echo
done

exit 0
