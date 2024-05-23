#include <iostream>
#include "glad/glad.h"
#include "ftmatrix.hpp"
#include "ftwindow.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// settings
int main()
{
	ftwindow window;

	if(window.init("RT") || window.makeContext())
		return (-1);
	window.setFrameBufferSizeCallback(framebuffer_size_callback);

	window.render();

	return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	std::cout << "width: " << width << "\nheight: " << height << std::endl;
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}