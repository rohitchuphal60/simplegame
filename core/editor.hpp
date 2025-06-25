#pragma once
#include "screen.hpp"

class Editor {
public:
    Editor(Screen* s);
    void init();
    void run();

private:
    Screen* screen;
};
