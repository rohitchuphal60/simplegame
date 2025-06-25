#include "editor.hpp"

Editor::Editor(Screen* s) : screen(s) {}

void Editor::init() {
    screen->init();
}

void Editor::run() {
    screen->clear();
    screen->moveCursor(0, 0);
    screen->drawLine("Welcome to Vim Clone!");
    screen->refresh();
    char key = screen->readKey();
}
