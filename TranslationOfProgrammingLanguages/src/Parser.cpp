#include "Parser.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

//***************************
//*	     CONSTRUCTOR        *
//***************************

Parser::Parser(vector <Token> tokens)
{
	cout << "Parsing Tokens..." << endl;
	this->code = tokens;
	for (Token token : tokens) {
		cout << token.getType() << " " << token.getValue() << endl;
		syntaxAnalyzer(token);
	}
}



//***************************
//*		   METHODS          *
//***************************
void Parser::syntaxAnalyzer(Token token)
{
	if (token.getType()=="KEYWORD") {// first token in the line
		if (token.getValue()=="var") {

		}
		else if (token.getValue() == "input") {

		}
		else if (token.getValue() == "output") {

		}
		else if (checkNext(token) == "IDENTIFIER" || checkNext(token) == "INT") {
			 
		}
	}
}

void Parser::checkCurrent()
{
}

string Parser::checkNext(Token token)
{
	for (Token current : code) {

	}

	return "ERROR";
}

void Parser::match()
{
}

void Parser::nextToken()
{
}

void Parser::breakParse()
{
	cout << "ERROR: ";
	exit(0);
}