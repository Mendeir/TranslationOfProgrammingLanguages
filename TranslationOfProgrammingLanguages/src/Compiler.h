#ifndef _COMPILER_H_
#define _COMPILER_H_

#include "Lexer.h"
#include "TypeCheck.h"

class Compiler
{
	private:
	Lexer lexer;
	TypeCheck typeCheck;

	public:
	Compiler(string fileName);
	void compileCode();
};

#endif