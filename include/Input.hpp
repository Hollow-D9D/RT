#include <GLUT/glut.h>
// #include <GL/gl.h> 
// #include <GL/glu.h>
// #include <GL/glut.h>
#include <iostream>

class Input
{
public:
    static Input&   getInstance();
    static void     keyboardCallback(unsigned char key, int x, int y);

private:
    void ESC(unsigned char key, int x, int y);

private:
    Input(/* args */);
    ~Input();

    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;
};

