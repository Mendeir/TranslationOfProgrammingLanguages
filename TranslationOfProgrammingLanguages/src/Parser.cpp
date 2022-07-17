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
	this->index = 0;


	syntaxAnalyzer();

	/*
	for (int i = 0; i < tokens.size(); i++) {
		cout << "Type: " << tokens[i].getType() << " | Value: \"" << tokens[i].getValue() << "\"\n";//for debugging
		syntaxAnalyzer(tokens[i], i);
	}
	*/
}



//***************************
//*		   METHODS          *
//***************************
void Parser::syntaxAnalyzer()
{
	while (true) {
		cout << "Type: " << this->code.at(this->index).getType() << " | Value: \"" << this->code.at(this->index).getValue() << "\"\n";//for debugging
		if (this->code.at(this->index).getType() == "KEYWORD") {// if current token is a keyword
			if (this->code.at(this->index).getValue() == "var") {// VARIABLE
				if (nextType(this->index) == "IDENTIFIER") {
					variables[this->code.at(this->index+1).getValue()] = NULL; // create empty variable
					nextToken();
					continue;
				}
			}
			else if (this->code.at(this->index).getValue() == "output") {// OUTPUT
				if (nextType(this->index) == "IDENTIFIER") {
					//insert Master Carl's function
				}
			}
			else {

			}
		}
		else if (this->code.at(this->index).getType() == "IDENTIFIER") {// if current token is an identifier
			if (variables.find(this->code.at(this->index).getValue()) != variables.end()) {// check if variable exists
				// found
				if (nextType(this->index) == "ASSIGN_OP") {
					variables[this->code.at(this->index).getValue()] = NULL; // create empty variable
					nextToken();
					continue;
				}
				else if (nextType(this->index) == "TERMINATOR") {// if no assigned value yet
					nextToken();
					continue;
				}
				else {
					breakParse();
				}
			}
			else {
				// not found
				cout << "Identifier (" + this->code.at(this->index).getValue() + ") NOT found...";
				breakParse();
			}

		}
		else if(this->code.at(this->index).getType() == "ASSIGN_OP") {
			string var_name = this->code.at(this->index - 1).getValue();

			vector <Token> expression; // vector containing combination of literals and operators
			nextToken();
		
			while (this->code.at(this->index).getType() != "TERMINATOR") {// puts tokens in the expr in the vector
				expression.push_back(code.at(this->index));
				nextToken();
			}

			variables[var_name] = solvExpr(expression);
			continue;
		}
		else if (this->code.at(this->index).getType() == "TERMINATOR") {
			nextToken();
		}
	}
	
}

int Parser::solvExpr(vector <Token> expression)
{
	//return 69;
	int result = 0;

	for (Token num : expression) {
		result += stoi(num.getValue());
	}
	return result;
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
	cout << this->code.size() << " " << this->index << " " << this->code.at(this->index).getValue() << endl;
	if (this->index < this->code.size()-1) {
		this->index += 1;
	}
	else {
		endCode();
		return;
	}
}

void Parser::breakParse()
{
	cout << "ERROR: ";
	//error_message("IDENTIFIER or INT expected after" + token.getValue());
	exit(0);
}

void Parser::endCode()
{
	cout << "End of program reached... <3" << endl;
	cout << "LIST OF VARIABLES...\n";
	for (auto it = variables.cbegin(); it != variables.cend(); ++it) {
		cout << "{" << (*it).first << ": " << (*it).second << "}\n";
	}
	exit(0);
}