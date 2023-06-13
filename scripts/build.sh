#! /bin/bash

mkdir lib
cd lib
git clone https://github.com/google/googletest.git
cd ..
mkdir build
cd build
cmake ..
make -j4
sudo make install