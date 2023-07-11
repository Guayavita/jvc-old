$root = Get-Location
if (-not (Test-Path "$root\llvm-project")) {
    git clone --depth 1 --branch llvmorg-16.0.6 https://github.com/llvm/llvm-project.git "$root\llvm-project"
}
Set-Location "$root\llvm-project"
cmake -B cmake-build -S llvm -DCMAKE_INSTALL_PREFIX="$root\llvm-project\build\" `
        -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="llvm;" `
        -DLLVM_HOST_TRIPLE=x86_64 -DLLVM_INSTALL_UTILS=ON -DLLVM_PARALLEL_LINK_JOBS=2 -G Ninja
Set-Location "$root\llvm-project\cmake-build"
ninja -j 4 install
Set-Location "$root"