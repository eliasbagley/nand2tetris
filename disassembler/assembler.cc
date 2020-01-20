#include "parser.h"
#include "code.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Converts an A instruction from binary to assembly
 *
 * examples:
 * 0000000000000001 -> @1
 * 0000000000000011 -> @3
 */
std::string assembleAInstruction(std::string instruction) {
  std::string binaryValue = instruction.substr(1, 15);
  int intValue = stoi(binaryValue, 0, 2);
  return "@" + std::to_string(intValue);
}


/**
 * Converts a C instruction from binary to assembly
 *
 * examples:
 * 1110100000000111 -> 0;JMP //TODO check to see if this instruction is right
 */
std::string assembleCInstruction(std::string instruction) {
  vector<string> bits = getBits(instruction);

  string aBit = getABit(bits);
  string cBits = getCBits(bits);
  string destBits = getDestBits(bits);
  string jumpBits = getJumpBits(bits);

  string comp = assembleCompBits(aBit, cBits);
  string dest = assembleDestBits(destBits);
  string jump = assembleJumpBits(jumpBits);

  if (!dest.empty()) {
    return dest + "=" + comp;
  }

  if (!jump.empty()) {
    return comp + ";" + jump;
  }

    return dest + "=" + comp + ";" + jump;
}

/**
 * Assembles a HACK instruction from binary to HACK assembly
 *
 * example:
 * TODO check actual instructiosn
 * 1110100000000111 -> 0;JMP
 * 0110100000000111 -> @234
 *
 */
std::string assemble(std::string instruction) {
  if (isAInstruction(instruction)) {
    return assembleAInstruction(instruction);
  }
  return assembleCInstruction(instruction);
}

int main() {
  //TODO take filename on STDIN
  //std::vector<std::string> instructions = parse("add/Add.asm");
  std::vector<std::string> instructions = parse("Rect.hack");
  for (auto & instr : instructions) {
    if (instr.substr(0, 2) == "//") {
      // Skip comments
      continue;
    }

    std::cout << assemble(instr) << "\n";
  }
  return 0;
}
