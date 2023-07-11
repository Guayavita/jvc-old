#!/usr/bin/env bash

root=$(pwd)
[ ! -d "${root}/llvm-project" ] &&  git clone --depth 1 --branch llvmorg-16.0.6 https://github.com/llvm/llvm-project.git
pushd "${root}/llvm-project"
cd "$(pwd)"
cmake -B cmake-build -S llvm -DCMAKE_INSTALL_PREFIX=./build/ \
        -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="llvm;" \
        -DLLVM_INSTALL_UTILS=ON -DLLVM_PARALLEL_LINK_JOBS=2 -G Ninja
pushd "${root}/llvm-project/cmake-build"
cd "$(pwd)"
ninja -j 4 install
#cd "$root"