#include "parser.h"
#include <string>
#include <iostream>
#include <vector>


bool testInstructionIsAInstruction() {
  std::string instruction = "0111111111111111";
  return isAInstruction(instruction);
}

bool testInstructionIsCInstruction() {
  std::string instruction = "1111111111111111";
  return isCInstruction(instruction);
}

bool testGetBits() {
  std::string instruction = "111accccccdddjjj";
  std::vector<std::string> bits = getBits(instruction);
  return getABit(bits) == "a"
    && getCBits(bits) == "cccccc"
    && getDestBits(bits) == "ddd"
    && getJumpBits(bits) == "jjj";
}

std::string passOrFail(bool pass) {
  if (pass) {
    return "Pass";
  }
  return "Fail";
}

int main() {
  std::cout << "testInstructionIsAInstruction: " << passOrFail(testInstructionIsAInstruction()) << std::endl;
  std::cout << "testInstructionIsCInstruction: " << passOrFail(testInstructionIsCInstruction()) << std::endl;
  std::cout << "testGetBits: " << passOrFail(testGetBits()) << std::endl;
  return 0;
}

