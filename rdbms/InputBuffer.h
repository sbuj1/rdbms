#pragma once

#include <string>

class InputBuffer
{
private:
	std::string buffer;

public: 
	InputBuffer();
	void read_input();
	void close_input_buffer(InputBuffer* inputBuffer);
	void print_prompt();
	std::string getBuffer() { return buffer; }
};

