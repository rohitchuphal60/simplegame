#include "command_parser.hpp"  
#include <iostream>

void CommandParser::execute(const std::string& cmd) {
    std::cout << "Command executed: " << cmd << std::endl;
}
