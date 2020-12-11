#!/bin/bash
#COSC 350
#Keith Flagg

echo "Enter the directory name in ($PWD):"
read dir

if [ -d $dir ]; then
  echo "The directory was found!"
else
  echo "Err: directory was not found, bye!"
  exit 1
fi

cd $dir

attempts=0
echo "Enter the name of your text file:"

while [ $attempts -lt 3 ]
do
  read filename
  if [ -e $filename ];
  then
    echo "File was found!"
    break
  else
    attempts=$(( attempts+1 ))

    if [ $attempts -eq 3 ]; then
      echo "The file was not found, attempts 3 of 3 used!"
      exit 2
    else
      echo "File not found, please try again, $attempts of 3 attempts used!"
    fi
  fi
done

echo "Please enter a word to search for in $file"
read word

if grep -q $word $filename; then
  echo "$word FOUND!"
else
  echo "$word NOT FOUND"
fi

exit 0
