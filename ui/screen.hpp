#pragma once
#include <string>

class Screen {
public:
    void init();
    void clear();
    void refresh();
    void drawLine(const std::string& line);
    void moveCursor(int x, int y);
    char readKey();
};
