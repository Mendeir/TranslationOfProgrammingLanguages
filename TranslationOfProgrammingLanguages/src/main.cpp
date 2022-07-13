#include "Lexer.h"
#include "Token.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	Token test2("type", "value");
	cout << test2.getType() << '\n';
	test.retrieveFile();
	//test.displayCode();

	cout << test.isComment("test") << '\n';
	cout << test.isComment("test ") << '\n';
	return 0;
}