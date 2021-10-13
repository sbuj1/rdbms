#include "InputBuffer.h"
#include <iostream>
#include <string>

InputBuffer::InputBuffer() {
	std::string buffer = "";
}

void InputBuffer::read_input()
{
	std::getline(std::cin, buffer);
	if (buffer.length() <= 0) {
		std::cout << "Error reading input" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void InputBuffer::close_input_buffer(InputBuffer* inputBuffer)
{
	delete inputBuffer;
}

void InputBuffer::print_prompt() { std::cout << "db > "; }