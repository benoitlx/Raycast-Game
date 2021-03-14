#!/bin/bash

echo "** Start Compiling **"

make

if [ "$1" = '-d' ]
then
	echo "Deleting obj files"
	make cleanObj
fi

echo "** Done **"

if [ "$1" = '-r' ]
then
	echo "Launching Program"
	./RaycastGame
fi

