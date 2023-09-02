#!/bin/bash

echo ====================== Running CMake... 
cmake -S . -B ./build/WSL

cd build/WSL/

echo ====================== Running Makefile...
make

echo ====================== Running executable...
mv src/first-opengl-project ../../bin
cd ../../bin
./first-opengl-project
