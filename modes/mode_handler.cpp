#include "mode_handler.hpp"

void ModeHandler::handleInput(char key, Buffer& buffer, bool& running) {
    if (mode == Mode::NORMAL) {
        if (key == 'i') mode = Mode::INSERT;
        if (key == 'q') running = false;
    } else if (mode == Mode::INSERT) {
        if (key == 27) mode = Mode::NORMAL; // ESC
        else buffer.insertChar(key);
    }
}
