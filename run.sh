#!/usr/bin/env sh

cd build/ || mkdir build/ && cd build/ || exit
cmake ../
make
cd ../
build/optimization_pt3
