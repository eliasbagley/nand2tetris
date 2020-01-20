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
  return instruction[0] == '0';
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

  std::string a = instruction.substr(3, 1);
  std::string c = instruction.substr(4, 6);
  std::string d = instruction.substr(10, 3);
  std::string j = instruction.substr(13, 3);

  bits.push_back(a);
  bits.push_back(c);
  bits.push_back(d);
  bits.push_back(j);
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
