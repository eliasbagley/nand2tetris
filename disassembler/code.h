#include <string>
#include <map>

std::map<std::string, std::string> buildCMap();
std::map<std::string, std::string> buildCAMap();
std::map<std::string, std::string> buildDestMap();
std::map<std::string, std::string> buildJumpMap();

std::string assembleCompBits(std::string aBit, std::string cBits);
std::string assembleDestBits(std::string destBits);
std::string assembleJumpBits(std::string jumpBits);

