// rdbms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <exception>

#include "InputBuffer.h"
#include "Command.h"

int main(int argc, char* argv[])
{
	InputBuffer *newBuffer = new InputBuffer();
	while (true) {
		newBuffer->print_prompt();
		newBuffer->read_input();

		Command* newCommand = new Command();

		if (newBuffer->getBuffer().at(0) == '.') {
			try {
				newCommand->do_meta_command(newBuffer);
				continue;
			}
			catch (std::exception& e) {
				std::cout << e.what() << newBuffer->getBuffer() << std::endl;
				continue;
			}
		}

		try {
			newCommand->prepare_statement(newBuffer, newCommand);
		}
		catch (std::exception& e) {
			std::cout << e.what() << newBuffer->getBuffer() << std::endl;
			continue;
		}

		newCommand->execute_statement(newCommand);
		std::cout << "Executed." << std::endl;
	}
}
