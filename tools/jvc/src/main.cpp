#include <guajavita/jvLLVM.h>
#include <guajavita/version.h>
#include <cobalt.hpp>
#include <iostream>
int main(){
  std::cout << guajavita::getGuajavitalangVersion();
  guajavita::getLLVM();
  return 0;
}