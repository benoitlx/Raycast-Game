#!/bin/sh

echo Start Compiling
g++ -c ~/Dev/cpp/raycastingv1.0/src/main.cpp ~/Dev/cpp/raycastingv1.0/src/Camera.cpp  ~/Dev/cpp/raycastingv1.0/src/Map.cpp
g++ main.o Camera.o Map.o -o raycastSFML -lsfml-graphics -lsfml-window -lsfml-system
echo Done	

./raycastSFML
