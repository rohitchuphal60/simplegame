// main.cpp
#include "ui/opengl_screen.hpp"

int main() {
    OpenGLScreen gui;
    gui.init();
    gui.mainLoop();  // render editor buffer with OpenGL
    gui.cleanup();
    return 0;
}
