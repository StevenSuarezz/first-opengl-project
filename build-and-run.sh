#!/bin/bash

echo ====================== Running CMake... 
cmake -S . -B ./build/WSL

cd build/WSL/

echo ====================== Running Makefile...
make

cd src/

echo ====================== Running executable...
./first-opengl-project
