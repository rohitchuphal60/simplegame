// ui/opengl_screen.hpp
#pragma once

class OpenGLScreen {
public:
    void init();
    void renderText(const std::string& text, float x, float y);
    void mainLoop();
    void cleanup();
};
