#include "Compiler.h"

Compiler::Compiler(string fileName)
	:lexer(fileName)
{
}

void Compiler::compileCode()
{
	lexer.retrieveFile();
	lexer.tokenize();
}