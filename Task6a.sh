#!/bin/bash
#COSC 350
#Keith Flagg
for ((i=1; i<=5; i++)); do
  for((j=1; j<=i; j++)); do
    printf "$i"
  done
  echo "" 
done