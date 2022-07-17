#include "Compiler.h"
#include <iostream>

using namespace std;

Compiler::Compiler(string fileName)
	:lexer(fileName)
{
}

void Compiler::compileCode()
{
	lexer.retrieveFile();
	lexer.tokenize();

	typeCheck.checkTokens(lexer.getTokens());
	cout << typeCheck.getResult();
}