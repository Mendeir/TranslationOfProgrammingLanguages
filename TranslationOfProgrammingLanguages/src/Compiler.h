#ifndef _COMPILER_H_
#define _COMPILER_H_

#include "Lexer.h";

class Compiler
{
	private:
	Lexer lexer;

	public:
	Compiler(string fileName);
	void compileCode();
};

#endif