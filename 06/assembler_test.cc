#include "assembler.h"
#include <iostream>


bool testAssembleAInstruction1() {
  return assembleAInstruction("@1") == "0000000000000001";
}

std::string passOrFail(bool pass) {
  if (pass) {
    return "Pass";
  }
  return "Fail";
}

int main() {
  std::cout << "testAssembleAInstruction1: " << passOrFail(testAssembleAInstruction1()) << std::endl;
  return 0;
}

