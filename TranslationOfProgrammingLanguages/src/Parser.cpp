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
	cout << "\nParsing Tokens...\nProgram Output:\n\n";
	this->code = tokens;
	this->index = 0;

	syntaxAnalyzer();
}

//***************************
//*		   METHODS          *
//***************************
void Parser::syntaxAnalyzer()
{
	while (true) {
		//cout << "Type: " << this->code.at(this->index).getType() << " | Value: \"" << this->code.at(this->index).getValue() << "\"\n";//for debugging
		if (this->code.at(this->index).getType() == "KEYWORD") {// if current token is a keyword
			if (this->code.at(this->index).getValue() == "var") {// VARIABLE
				if (nextType(this->index) == "VARIABLE") {
					variables[this->code.at(this->index + 1).getValue()] = NULL; // create empty variable
					nextToken();
					continue;
				}
			}
			else if (this->code.at(this->index).getValue() == "output") {// OUTPUT
				if (nextType(this->index) == "VARIABLE") {
					//insert Master Carl's function
					output(this->code.at(this->index + 1)); //+1 on index because current token is "output"
					nextToken();
					continue;
				}
			}
			else {
				if (nextType(this->index) == "IDENTIFIER") {
					cout << "\nInput:";
					cin >> variables[this->code.at(this->index + 1).getValue()];
				}
				nextToken();
			}
		}
		else if (this->code.at(this->index).getType() == "VARIABLE") {// if current token is an VARIABLE
			if (variables.find(this->code.at(this->index).getValue()) != variables.end()) {// check if variable exists
				// found
				if (nextType(this->index) == "ASSIGN_OPERATOR") {
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
				cout << "VARIABLE (" + this->code.at(this->index).getValue() + ") NOT found...";
				breakParse();
			}

		}
		else if (this->code.at(this->index).getType() == "ASSIGN_OPERATOR") {
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
	//example input "5 + 8 * 10 + num"

	vector <Token> temp;
	int result = stoi(expression.at(0).getValue()); //first literal

	for (int i = 1; i < expression.size(); i++) {// look for */
		//cout << expression.at(i).getValue();
		if (expression.at(i).getType() == "LITERAL") {
			if (nextType(i) == "OPERATOR" || i == expression.size() - 1) {
				continue;
			}
			else {
				continue;
			}
		}
		else if (expression.at(i).getType() == "ARITH_OPERATOR") {
			if (expression.at(i).getValue() == "*") {
				result *= stoi(expression.at(i+1).getValue());
				continue;
			}
			else if (expression.at(i).getValue() == "/") {
				result /= stoi(expression.at(i+1).getValue());
				continue;
			}
			else if (expression.at(i).getValue() == "+") {
				result += stoi(expression.at(i+1).getValue());
				continue;
			}
			else if (expression.at(i).getValue() == "-") {
				result -= stoi(expression.at(i+1).getValue());
				continue;
			}
		}
	}
	return result;
}

string Parser::nextType(int current_index)
{
	return code.at(static_cast<std::vector<Token, std::allocator<Token>>::size_type>(current_index) + 1).getType();
}

void Parser::nextToken()
{
	//cout << this->code.size() << " " << this->index << " " << this->code.at(this->index).getValue() << endl;
	if (this->index >= this->code.size() - 1) {
		endCode();
		return;
	}
	else {
		this->index += 1;
	}
}

void Parser::breakParse()
{
	cout << "ERROR: ";
	//error_message("VARIABLE or LITERAL expected after" + token.getValue());
	exit(0);
}

void Parser::endCode()
{
	cout << "\n\n\nEnd of program reached... <3";
	/*
	cout << "LIST OF VARIABLES...\n";
	for (auto it = variables.cbegin(); it != variables.cend(); ++it) {
		cout << "{" << (*it).first << ": " << (*it).second << "}\n";
	}
	*/
	exit(0);
}

void Parser::output(Token token) {
	if (variables.find(token.getValue()) != variables.end()) {
		cout << variables[token.getValue()];
	}
	else {
		breakParse();
	}
}