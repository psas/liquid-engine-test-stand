#!/bin/sh

if [ -z "$1" ]; then
  echo "Usage: readscript.sh <filename>"
  exit
fi

filename=`find -name "$1*" -print -quit`
echo "Using file $filename"
while read line <&3
do
  if [ -z "$line" -o "$line" = '\n' ]; then
    continue
  fi

  line=$(echo $line | sed 's/1\.\|-//g')
  echo $line
  
  read action
  if [ "$action" != "s" ]; then
    pico2wave -w=/tmp/temp.wav "$line"
    aplay /tmp/temp.wav -q
  fi
done 3< $filename
