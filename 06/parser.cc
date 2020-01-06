#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> parse(std::string filename) {
  std::vector<std::string> instructions;
  std::ifstream file(filename);
  std::string str;
  while (std::getline(file, str)) {
    instructions.push_back(str);
  }
  return instructions;
}

bool isAInstruction(std::string instruction) {
  return false;
}
bool isCInstruction(std::string instruction) {
  return !isAInstruction(instruction);
}

// [a bit, c bits, dest bits, jump bits]
// throws if not a C instruction
std::vector<std::string> getBits(std::string instruction) {
  if (!isCInstruction(instruction)) {
    throw "Must be a C instruction to decode bits";
  }

  std::vector<std::string> bits;

  //TODO parse from actual instruction
  bits.push_back("1");
  bits.push_back("101010");
  bits.push_back("111");
  bits.push_back("101");
  return bits;
}

std::string getABit(std::vector<std::string> bits) {
  return bits[0];
}

std::string getCBits(std::vector<std::string> bits) {
  return bits[1];
}

std::string getDestBits(std::vector<std::string> bits) {
  return bits[2];
}

std::string getJumpBits(std::vector<std::string> bits) {
  return bits[3];
}
