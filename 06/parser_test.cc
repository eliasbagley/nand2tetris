#include "parser.h"
#include <string>
#include <iostream>
#include <vector>


bool testInstructionIsAInstruction() {
  std::string instruction = "@1";
  return isAInstruction(instruction);
}

bool testInstructionIsCInstruction() {
  std::string instruction = "D=M+1";
  return isCInstruction(instruction);
}

bool testGetDest1() {
  std::string instruction = "D=M+1";
  std::string dest = getDest(instruction);
  return dest == "D";
}

bool testGetDest2() {
  std::string instruction = "D=M+1;JMP";
  std::string dest = getDest(instruction);
  return dest == "D";
}

bool testGetComp1() {
  std::string instruction = "D=M+1;JMP";
  std::string comp = getComp(instruction);
  return comp == "M+1";
}
bool testGetComp2() {
  std::string instruction = "D=M+1";
  std::string comp = getComp(instruction);
  return comp == "M+1";
}

bool testGetJump1() {
  std::string instruction = "D=M+1";
  std::string jump = getJump(instruction);
  return jump.empty();
}
bool testGetJump2() {
  std::string instruction = "D=M+1;JMP";
  std::string jump = getJump(instruction);
  return jump == "JMP";
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
  std::cout << "testGetDest1: " << passOrFail(testGetDest1()) << std::endl;
  std::cout << "testGetDest2: " << passOrFail(testGetDest2()) << std::endl;
  std::cout << "testGetComp1: " << passOrFail(testGetComp1()) << std::endl;
  std::cout << "testGetComp2: " << passOrFail(testGetComp2()) << std::endl;
  std::cout << "testGetJump1: " << passOrFail(testGetJump1()) << std::endl;
  std::cout << "testGetJump2: " << passOrFail(testGetJump2()) << std::endl;
  return 0;
}

