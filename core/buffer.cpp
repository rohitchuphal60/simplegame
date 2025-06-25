#include "buffer.hpp"
#include <fstream>

void Buffer::load(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    if (lines.empty()) lines.push_back("");
}

void Buffer::render(Screen& screen) {
    for (const auto& line : lines) {
        screen.drawLine(line);
    }
}

void Buffer::insertChar(char c) {
    lines[cursorY].insert(cursorX, 1, c);
    cursorX++;
}
