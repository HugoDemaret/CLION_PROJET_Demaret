#!/usr/bin/env bash
echo "Compiling from source..."
cd cmake-build-debug
make
echo "Compiled !"
cd ..
echo "Program will start soon..."
cp cmake-build-debug/Projet_BDDA_DEMARET .
./Projet_BDDA_DEMARET
echo "End"
