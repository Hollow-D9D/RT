#include <iostream>
#include "ftmatrix.hpp"
#include "ftwindow.hpp"

int main(int argc, char** argv)
{	
	ftwindow::getInstance().init("RT", argc, argv);

	return 0;
}