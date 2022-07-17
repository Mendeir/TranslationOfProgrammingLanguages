#include "Lexer.h"
#include "Token.h"
#include "TypeCheck.h"
#include "Parser.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	Token test2("type", "value");
	test.retrieveFile();
	test.displayCode();
	test.tokenize();
	//test.addToken("Malupet", "Ako");
	cout << '\n';
	test.displayTokens();

	TypeCheck type;
	type.checkTokens();
	cout << type.getResult();

	//test.displayCode();

	//cout << test.isComment("test") << '\n';
	//cout << test.isComment("test ") << '\n';


	vector <Token> code;
	//var num = 0;
	Token token01("KEYWORD", "var");
	Token token02("IDENTIFIER", "num");
	Token token03("ASSIGN_OP", "=");
	Token token04("INT", "230192");
	Token token05("TERMINATOR", ";");

	code.push_back(token01);
	code.push_back(token02);
	code.push_back(token03);
	code.push_back(token04);
	code.push_back(token05);
	Parser parser01(code);

	return 0;
}