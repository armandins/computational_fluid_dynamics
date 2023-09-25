#! /bin/bash
#
cp multigrid_poisson_1d.hpp /$HOME/include
#
g++ -c -Wall multigrid_poisson_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv multigrid_poisson_1d.o ~/libcpp/multigrid_poisson_1d.o
#
echo "Normal end of execution."
