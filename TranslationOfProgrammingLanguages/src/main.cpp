#include "Lexer.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	test.retrieveFile();
	//test.displayCode();

	cout << test.isComment("test") << '\n';
	cout << test.isComment("test ") << '\n';
	return 0;
}