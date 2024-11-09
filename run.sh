#!/usr/bin/env sh

mkdir -p build/
cd build/ || exit
cmake ../
make
cd ../
build/optimization_pt3
