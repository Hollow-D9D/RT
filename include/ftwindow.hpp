#pragma once
#include <stdint.h>
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

struct GLFWwindow;

class ftwindow
{
public:
    ftwindow() {}
    bool init(const char* windowName, uint32_t width = SCR_WIDTH, uint32_t height = SCR_HEIGHT);
    bool makeContext();

    void setFrameBufferSizeCallback(void (*func) (GLFWwindow *, int, int));

    void render();

    void processInput();

private:

    GLFWwindow* window;
};