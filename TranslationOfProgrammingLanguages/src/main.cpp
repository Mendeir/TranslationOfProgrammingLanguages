#include "Lexer.h"
#include "Token.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	
	test.tokenize();
	test.displayTokens();
	//test.retrieveFile();
	//test.displayCode();

	//cout << test.isComment("test") << '\n';
	//cout << test.isComment("test ") << '\n';
	return 0;
}