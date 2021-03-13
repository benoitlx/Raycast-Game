#!/bin/bash

echo "** Start Compiling **"

make 
make cleanObj

echo "** Done **"

if [ "$1" = '-r' ]
then
	./RaycastGame
fi

