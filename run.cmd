@echo off
mkdir build
cd build
cmake ..
make
cd ..
build/optimization_pt3.exe
