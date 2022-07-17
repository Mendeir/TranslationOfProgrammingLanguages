#include "TypeCheck.h"
#include "Lexer.h"
#include "Token.h"
#include <iostream>

using namespace std;

TypeCheck::TypeCheck()
{
	this->result = "";
}

void TypeCheck::checkTokens()
{
	Lexer lexer("code.txt");
	vector <string> variables;
	this->result = "There are no errors";
	// Store variables that are defined
	for (int i = 0; i < lexer.getTokens().size(); i++)
	{
		if (lexer.getTokens().at(i).getValue() == "var")
		{
			variables.push_back(lexer.getTokens().at(i + 1).getValue());		
		}
	}

	//Check if variables are all declared
	for (int i = 0; i < lexer.getTokens().size(); i++)
	{
		if (lexer.isVariable(lexer.getTokens().at(i).getValue()))
		{
			
			for (int j = 0; j < variables.size(); j++)
			{
				if (lexer.getTokens().at(i).getValue() == variables.at(j))
				{
					result = "There are no errors";
					
				}
				else
				{
					result += "\nError " + lexer.getTokens().at(i).getValue() + "is not declared";
				}
			}
		}
		
	}


	//Compare if the values of the variables is integer
	for (int i = 0; i < lexer.getTokens().size(); i++) 
	{
		for (int j = 0; j < variables.size(); j++)
		{
			if (lexer.getTokens().at(j).getValue() == variables.at(j))
			{
				if (lexer.getTokens().at(j + 1).getValue() == "=" && !isdigit(stoi(lexer.getTokens().at(j + 2).getValue())))
				{
					result += "\nError" + lexer.getTokens().at(j).getValue() + " value is not an integer";
				}
				
			}
		}
	}
	
	
}

string TypeCheck::getResult()
{
	return this->result;
}