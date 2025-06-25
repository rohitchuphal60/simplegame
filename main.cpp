// main.cpp
#include "opengl_screen.hpp"

int main() {
    OpenGLScreen screen;
    screen.init();
    screen.mainLoop();
    screen.cleanup();
    return 0;
}
