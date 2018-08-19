#!/bin/sh -x
for i in *.svg; do
#	rsvg-convert -f pdf "$i" -o "$i".pdf
	myVar=$(echo "$i" | cut -d'.' -f 1);
	rsvg-convert -f pdf "$i" -o "$myVar".pdf
#	echo "$myVar";
done	 
