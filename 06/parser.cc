#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>


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
  return instruction[0] == '@';
}
bool isCInstruction(std::string instruction) {
  return !isAInstruction(instruction);
}

bool hasDest(std::string instruction) {
  return !getDest(instruction).empty();
}

bool hasJump(std::string instruction) {
  return !getJump(instruction).empty();
}


std::string getComp(std::string instruction) {
  if (hasDest(instruction) && hasJump(instruction)) {
      std::size_t compStart = instruction.find_first_of("=");
      std::size_t jumpStart = instruction.find_first_of(";");
      return instruction.substr(compStart+1, jumpStart - compStart -1);
  } else if (hasDest(instruction)) {
      std::size_t compStart = instruction.find_first_of("=");
      return instruction.substr(compStart+1);
  }

  std::size_t jumpStart = instruction.find_first_of(";");
  return instruction.substr(0, jumpStart);
}


std::string getDest(std::string instruction) {
  std::size_t found = instruction.find_first_of("=");

  if (found != std::string::npos) {
    return instruction.substr(0, found);
  }

  return "";
}


std::string getJump(std::string instruction) {
  std::size_t found = instruction.find_first_of(";");

  if (found != std::string::npos) {
    return instruction.substr(found+1);
  }

  return "";
}
