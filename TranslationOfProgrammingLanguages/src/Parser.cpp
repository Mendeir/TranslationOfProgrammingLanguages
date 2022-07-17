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
	cout << "\nParsing Tokens...\n\n";
	this->code = tokens;
	for (int i = 0; i < tokens.size(); i++) {
		cout << "Type: " << tokens[i].getType() << " | Value: \"" << tokens[i].getValue() << "\"\n";//for debugging
		syntaxAnalyzer(tokens[i], i);
	}
}



//***************************
//*		   METHODS          *
//***************************
void Parser::syntaxAnalyzer(Token token, int index)
{
	if (token.getType() == "KEYWORD") {// first token in the line
		if (token.getValue() == "var") {

		}
		else if (token.getValue() == "input") {

		}
		else if (token.getValue() == "output") {

		}
		else if (nextType(index) == "IDENTIFIER" || nextType(index) == "INT") {
			 
		}
	}
	else if (token.getType() == "IDENTIFIER") {
		if (nextType(index) == "ASSIGN_OP") {
			variables[token.getValue()] = NULL;
		}
		else {
			breakParse();
		}
	}
	else {

	}
}

void Parser::checkCurrent()
{
}

string Parser::nextType(int current_index)
{
	return code.at(static_cast<std::vector<Token, std::allocator<Token>>::size_type>(current_index) + 1).getType();
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
	//error_message("IDENTIFIER or INT expected after" + token.getValue());
	exit(0);
}