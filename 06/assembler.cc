#include "parser.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> instructions = parse("add/Add.asm");
  for (auto & instr : instructions) {
    std::cout << instr << "\n";
  }
  return 0;
}
