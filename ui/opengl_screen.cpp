#include "ui/screen.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

static struct termios orig;

void Screen::init() {
    tcgetattr(STDIN_FILENO, &orig);
    atexit([]() { tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig); });

    struct termios raw = orig;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Screen::clear() {
    std::cout << "\x1b[2J\x1b[H";
}

void Screen::refresh() {
    std::cout.flush();
}

void Screen::drawLine(const std::string& line) {
    std::cout << line << "\r\n";
}

void Screen::moveCursor(int x, int y) {
    std::cout << "\x1b[" << y+1 << ";" << x+1 << "H";
}

char Screen::readKey() {
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
}
