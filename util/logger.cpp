#include "util/logger.hpp"
#include <iostream>

void Logger::log(const std::string& msg) {
    std::cerr << "[LOG] " << msg << std::endl;
}
