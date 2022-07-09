#include "Lexer.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	test.retrieveFile();
	test.displayCode();

	return 0;
}