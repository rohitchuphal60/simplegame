#pragma once
#include "screen.hpp"
#include <string>

class OpenGLScreen : public Screen {
public:
    void init() override;
    void clear() override;
    void refresh() override;
    void drawLine(const std::string& line) override;
    void moveCursor(int x, int y) override;
    char readKey() override;
    void mainLoop();
    void cleanup();
    ~OpenGLScreen() override;
};
