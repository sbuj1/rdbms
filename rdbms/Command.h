#pragma once

#include "InputBuffer.h"
#include <string>

class Command
{
private:
public:
	Command();
	enum class StatementType { STATEMENT_INSERT, STATEMENT_SELECT };
	StatementType statementType;
	void do_meta_command(InputBuffer* inputBuffer);
	void prepare_statement(InputBuffer* inputBuffer, Command* type);
	void execute_statement(Command* statement);
};
