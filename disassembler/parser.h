#include <string>
#include <vector>

std::vector<std::string> parse(std::string filename);

bool isAInstruction(std::string instruction);
bool isCInstruction(std::string instruction);

// [a bit, c bits, dest bits, jump bits]
// throws if not a C instruction
std::vector<std::string> getBits(std::string instruction);

std::string getABit(std::vector<std::string> instruction);
std::string getCBits(std::vector<std::string> instruction);
std::string getDestBits(std::vector<std::string> instruction);
std::string getJumpBits(std::vector<std::string> instruction);
