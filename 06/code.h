#include <string>
#include <map>

std::map<std::string, std::string> buildCMap();
std::map<std::string, std::string> buildDestMap();
std::map<std::string, std::string> buildJumpMap();

std::string assembleABit(std::string comp);
std::string assembleComp(std::string comp);
std::string assembleDest(std::string dest);
std::string assembleJump(std::string jump);
