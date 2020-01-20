#include "code.h"
#include <string>
#include <map>

using namespace std;

std::map<std::string, std::string> buildCMap() {
  std::map<std::string, std::string> m;
  m["101010"] = "0";
  m["111111"] = "1";
  m["111010"] = "-1";
  m["001100"] = "D";
  m["110000"] = "A";
  m["001101"] = "!D";
  m["110001"] = "!A";
  m["001111"] = "-D";
  m["110011"] = "-A";
  m["011111"] = "D+1";
  m["110111"] = "A+1";
  m["001110"] = "D-1";
  m["110010"] = "A-1";
  m["000010"] = "D+A";
  m["010011"] = "D-A";
  m["000111"] = "A-D";
  m["000000"] = "D&A";
  m["010101"] = "D|A";
  return m;
}

std::map<std::string, std::string> buildCAMap() {
  std::map<std::string, std::string> m;
  m["110000"] = "M";
  m["110001"] = "!M";
  m["110011"] = "-M";
  m["110111"] = "M+1";
  m["110010"] = "M-1";
  m["000010"] = "D+M";
  m["010011"] = "D-M";
  m["000111"] = "M-D";
  m["000000"] = "D&M";
  m["010101"] = "D|M";
  return m;
}

std::map<std::string, std::string> buildDestMap() {
  std::map<std::string, std::string> m;
  m["000"] = "";
  m["001"] = "M";
  m["010"] = "D";
  m["011"] = "MD";
  m["100"] = "A";
  m["101"] = "AM";
  m["110"] = "AD";
  m["111"] = "AMD";
  return m;
}

std::map<std::string, std::string> buildJumpMap() {
  std::map<std::string, std::string> m;
  m["000"] = "";
  m["001"] = "JGT";
  m["010"] = "JEQ";
  m["011"] = "JGE";
  m["100"] = "JLT";
  m["101"] = "JNE";
  m["110"] = "JLE";
  m["111"] = "JMP";
  return m;
}


std::string assembleCompBits(std::string aBit, std::string cBits) {
  if (aBit == "1") {
    return buildCAMap()[cBits];
  }

  return buildCMap()[cBits];
}

std::string assembleDestBits(std::string destBits) {
  return buildDestMap()[destBits];
}

std::string assembleJumpBits(std::string jumpBits) {
  return buildJumpMap()[jumpBits];
}

