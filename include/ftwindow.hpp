#pragma once
#include <stdint.h>
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

struct GLFWwindow;

class ftwindow
{
public:

    static ftwindow& getInstance();

    bool init(const char* windowName, int, char*[], uint32_t width = SCR_WIDTH, uint32_t height = SCR_HEIGHT);
    bool makeContext();

    static void render();

private:

    ftwindow() {}

    uint32_t _width;
    uint32_t _height;
    GLFWwindow* window;
};