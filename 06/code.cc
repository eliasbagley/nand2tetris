#include "code.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>

using namespace std;

std::map<std::string, std::string> buildCMap() {
  std::map<std::string, std::string> m;
  m["0"] = "101010";
  m["1"] = "111111";
  m["-1"] = "111010";
  m["D"] = "001100";
  m["A"] = "110000";
  m["!D"] = "001101";
  m["!A"] = "110001";
  m["-D"] = "001111";
  m["-A"] = "110011";
  m["D+1"] = "011111";
  m["A+1"] = "110111";
  m["D-1"] = "001110";
  m["A-1"] = "110010";
  m["D+A"] = "000010";
  m["D-A"] = "010011";
  m["A-D"] = "000111";
  m["D&A"] = "000000";
  m["D|A"] = "010101";
  m["M"] = "110000";
  m["!M"] = "110001";
  m["-M"] = "110011";
  m["M+1"] = "110111";
  m["M-1"] = "110010";
  m["D+M"] = "000010";
  m["D-M"] = "010011";
  m["M-D"] = "000111";
  m["D&M"] = "000000";
  m["D|M"] = "010101";
  return m;
}

std::map<std::string, std::string> buildDestMap() {
  std::map<std::string, std::string> m;
  m[""] = "000";
  m["M"] = "001";
  m["D"] = "010";
  m["MD"] = "011";
  m["A"] = "100";
  m["AM"] = "101";
  m["AD"] = "110";
  m["AMD"] = "111";
  return m;
}

std::map<std::string, std::string> buildJumpMap() {
  std::map<std::string, std::string> m;
  m[""] = "000";
  m["JGT"] = "001";
  m["JEQ"] = "010";
  m["JGE"] = "011";
  m["JLT"] = "100";
  m["JNE"] = "101";
  m["JLE"] = "110";
  m["JMP"] = "111";
  return m;
}

std::string assembleABit(string comp) {
  std::size_t found = comp.find_first_of("M");
  if (found != std::string::npos) {
    return "1";
  }
  return "0";
}

std::string assembleComp(std::string comp) {
  return buildCMap()[comp];
}

std::string assembleDest(std::string dest) {
  return buildDestMap()[dest];
}

std::string assembleJump(std::string jump) {
  return buildJumpMap()[jump];
}

