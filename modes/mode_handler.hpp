#pragma once
#include "core/buffer.hpp"

class ModeHandler {
public:
    void handleInput(char key, Buffer& buffer, bool& running);
private:
    enum class Mode { NORMAL, INSERT } mode = Mode::NORMAL;
};
