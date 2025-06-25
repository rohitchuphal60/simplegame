#pragma once
#include "core/buffer.hpp"
#include "ui/screen.hpp"
#include "modes/mode_handler.hpp"

class Editor {
public:
    void init();
    void run();
private:
    Buffer buffer;
    Screen screen;
    ModeHandler modeHandler;
    bool running = true;
};
