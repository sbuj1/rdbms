// rdbms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "InputBuffer.h"

int main(int argc, char* argv[])
{
	InputBuffer *newBuffer = new InputBuffer();
	while (true) {
		newBuffer->print_prompt();
		newBuffer->read_input();

		if (newBuffer->getBuffer().compare(".exit") == 0) {
			newBuffer->close_input_buffer(newBuffer);
			exit(EXIT_SUCCESS);
		}
		else {
			std::cout << "Unrecognized command " << newBuffer->getBuffer() << std::endl;
		}
	}
}
