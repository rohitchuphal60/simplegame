#pragma once
#include <string>

class Screen {
public:
    virtual void init() = 0;
    virtual void clear() = 0;
    virtual void refresh() = 0;
    virtual void drawLine(const std::string& line) = 0;  // ✅ PURE VIRTUAL
    virtual void moveCursor(int x, int y) = 0;
    virtual char readKey() = 0;
    virtual ~Screen() = default;
};
