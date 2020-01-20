#include "parser.h"
#include "code.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

/**
 * Converts an A instruction from assembly to binary
 *
 * examples:
 * @1 -> 0000000000000001
 * @3 -> 0000000000000011
 */
std::string assembleAInstruction(std::string instruction) {
  string decimalString = instruction.substr(1);
  int decimalInt = stoi(decimalString, 0, 10);
  string binaryString = bitset<15>(decimalInt).to_string();
  return "0" + binaryString;
}


/**
 * Converts a C instruction from binary to assembly
 *
 * examples:
 * 0;JMP -> 111accccccdddjjj
 */
std::string assembleCInstruction(std::string instruction) {
  string dest = getDest(instruction);
  string comp = getComp(instruction);
  string jump = getJump(instruction);

  string a = assembleABit(comp);
  string destBits = assembleDest(dest);
  string compBits = assembleComp(comp);
  string jumpBits = assembleJump(jump);
  return "111" + a + compBits + destBits + jumpBits;
}

/**
 * Assembles a HACK instruction from binary to HACK assembly
 *
 * example:
 * 0;JMP -> 111accccccdddjjj
 * @1 -> 0000000000000001
 *
 */
std::string assemble(std::string instruction) {
  if (isAInstruction(instruction)) {
    return assembleAInstruction(instruction);
  }
  return assembleCInstruction(instruction);
}

//TODO fix
int main() {
  //TODO take filename on STDIN
  std::vector<std::string> instructions = parse("add/Add.asm");
  for (auto & instr : instructions) {
    if (instr.substr(0, 2) == "//") {
      // Skip comments
      continue;
    }
    if (instr.empty()) {
      // Skip empty lines
      continue;
    }

    std::cout << assemble(instr) << "\n";
  }
  return 0;
}
