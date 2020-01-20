#include <string>
#include <vector>

std::vector<std::string> parse(std::string filename);

bool isAInstruction(std::string instruction);
bool isCInstruction(std::string instruction);

std::string getComp(std::string instruction);
std::string getDest(std::string instruction);
std::string getJump(std::string instruction);
