#include "opengl_screen.hpp"
#include <iostream>

OpenGLScreen::~OpenGLScreen() = default;

void OpenGLScreen::init() {
    std::cout << "OpenGL init()\n";
}

void OpenGLScreen::clear() {
    std::cout << "OpenGL clear()\n";
}

void OpenGLScreen::refresh() {
    std::cout << "OpenGL refresh()\n";
}

void OpenGLScreen::drawLine(const std::string& line) {
    std::cout << "OpenGL drawLine(): " << line << "\n";
}

void OpenGLScreen::moveCursor(int x, int y) {
    std::cout << "Move cursor to " << x << ", " << y << "\n";
}

char OpenGLScreen::readKey() {
    return 'a'; // stub
}

void OpenGLScreen::mainLoop() {
    // OpenGL main loop stub
}

void OpenGLScreen::cleanup() {
    std::cout << "Cleanup\n";
}
