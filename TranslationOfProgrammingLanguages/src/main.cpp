#include "Lexer.h"
#include "Token.h"
#include "Parser.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Hello World!" << '\n';
	Lexer test("code.txt");
	Token test2("type", "value");
	cout << test2.getType() << '\n';
	test.retrieveFile();
	test.tokenize();
	test.addToken("Malupet", "Ako");
	test.displayTokens();
	//test.displayCode();

	//cout << test.isComment("test") << '\n';
	//cout << test.isComment("test ") << '\n';

	vector <Token> code;
	//var num = 0;
	Token token01("KEYWORD", "var");
	Token token02("VARIABLE", "num");
	Token token03("ASSIGN_OPERATOR", "=");
	Token token04("LITERAL", "5");
	Token token05("ARITH_OPERATOR", "+");
	Token token06("LITERAL", "10");
	Token token07("ARITH_OPERATOR", "*");
	Token token08("LITERAL", "10");
	Token token09("ARITH_OPERATOR", "+");
	Token token10("LITERAL", "8");
	Token token11("TERMINATOR", ";");
	Token token12("KEYWORD", "output");
	Token token13("VARIABLE", "num");
	Token token14("TERMINATOR", ";");

	code.push_back(token01);
	code.push_back(token02);
	code.push_back(token03);
	code.push_back(token04);
	code.push_back(token05);
	code.push_back(token06);
	code.push_back(token07);
	code.push_back(token08);
	code.push_back(token09);
	code.push_back(token10);
	code.push_back(token11);
	code.push_back(token12);
	code.push_back(token13);
	code.push_back(token14);
	Parser parser01(code);

	return 0;
}