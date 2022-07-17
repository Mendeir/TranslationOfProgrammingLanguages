#include <string>
#include "Compiler.h"
#include "TypeCheck.h"
#include <iostream>
using namespace std;

int main() 
{

	string fileName = "code.txt";
	Lexer lexer(fileName);
	lexer.retrieveFile();
	lexer.tokenize();

	TypeCheck typeCheck;
	typeCheck.checkTokens(lexer.getTokens());
	cout << typeCheck.getResult();

	return 0;
}