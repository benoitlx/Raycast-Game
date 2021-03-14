#!/bin/bash

echo "** Start Compiling **"

make
mv *.o .gitignore/

echo "** Done **"

if [ "$1" = '-r' ]
then
	echo "Launching Program"
	./RaycastGame
fi

