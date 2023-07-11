# GuaJavita Compiler & Tools

## Build Requirements

1. Cmake
2. Ninja
3. Git
4. Python 3

## Build From Source

1. Clone this project
```shell
git clone https://github.com/GuaJavita/jvc.git
```
2. Run the `llvm.sh` or `llvm.ps1` scripts to download the llvm project  **This might take time**
   1.  You might need to enable powershell script execution in Windows
2. Create a build directory 
```shell
mkdir build
```
3. Execute
```shell
cd build
```
4. Execute
```shell
   cmake ../
```
5. Execute 
```shell
ninja
```

**Note**

Platform Independence: OS package versions of LLVM are typically specific to a particular operating system 
or distribution. By compiling LLVM locally, you can achieve platform independence.
You can build LLVM on your desired platform and use it across different systems or 
distributions without relying on specific OS package repositories.