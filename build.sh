#!/usr/bin/env bash

CORE_COUNT=$(grep -c ^processor /proc/cpuinfo)

rm -r build
mkdir build
cd build
echo "----- Generating CMake Makefiles -----"
cmake .. -DCMAKE_BUILD_TYPE=Release
echo "----- Producing ShoebillPlugin Release Executable -----"
#/c/msys64/mingw32/bin/mingw32-make.exe clean
#/c/msys64/mingw32/bin/mingw32-make.exe -j ${CORE_COUNT}

make clean
make -j ${CORE_COUNT}
echo "+++++ Build finished +++++"
