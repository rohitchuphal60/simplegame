#include "core/editor.hpp"
#include <iostream>

void Editor::init() {
    screen.init();
    buffer.load("sample.txt");
}

void Editor::run() {
    while (running) {
        screen.clear();
        buffer.render(screen);
        screen.moveCursor(buffer.cursorX, buffer.cursorY);
        screen.refresh();

        char key = screen.readKey();
        modeHandler.handleInput(key, buffer, running);
    }
}
