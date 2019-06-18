#!/bin/sh -x
# "sudo apt-get install librsvg2-bin" to use this script
for i in *.svg; do
	myVar=$(echo "$i" | cut -d'.' -f 1);
	rsvg-convert -f pdf "$i" -o "$myVar".pdf
done	 
