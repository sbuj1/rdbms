#include "Command.h"
#include "InputBuffer.h"
#include <iostream>
#include <string>
#include <exception>

Command::Command() {

}

struct InvalidCommandException : public std::exception {
	const char * what() const throw () {
		return "Unrecognized command ";
	}
};

struct InvalidStatementException : public std::exception {
	const char * what() const throw () {
		return "Unrecognized statement ";
	}
};

void Command::do_meta_command(InputBuffer* inputBuffer) {
	if (inputBuffer->getBuffer().compare(".exit") == 0) {
		inputBuffer->close_input_buffer(inputBuffer);
		exit(EXIT_SUCCESS);
	}
	else {
		throw InvalidCommandException();
	}
}

void Command::prepare_statement(InputBuffer* inputBuffer, Command* statement) {
	if (inputBuffer->getBuffer().compare("insert") == 0) {
		statement->statementType = Command::StatementType::STATEMENT_INSERT;
	}
	else if (inputBuffer->getBuffer().compare("select") == 0) {
		statement->statementType = Command::StatementType::STATEMENT_SELECT;
	}
	else {
		throw InvalidStatementException();
	}
}

void Command::execute_statement(Command* statement) {
	switch (statement->statementType) {
		case(Command::StatementType::STATEMENT_INSERT):
			std::cout << "Insert will be executed" << std::endl;
			break;
		case(Command::StatementType::STATEMENT_SELECT):
			std::cout << "Select will be executed" << std::endl;
			break;
	}
}