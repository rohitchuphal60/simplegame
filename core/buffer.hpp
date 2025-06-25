#pragma once
#include <vector>
#include <string>
#include "ui/screen.hpp"

class Buffer {
public:
    void load(const std::string& filename);
    void render(Screen& screen);
    void insertChar(char c);
    int cursorX = 0;
    int cursorY = 0;
private:
    std::vector<std::string> lines;
};
