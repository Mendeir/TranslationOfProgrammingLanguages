#include "TypeCheck.h"
#include <iostream>

using namespace std;

TypeCheck::TypeCheck()
{
	this->result = "";
}

void TypeCheck::checkTokens(vector <Token> tokens)
{
	
	vector <string> variables;
	this->result = "";
	
	// Store variables that are defined
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens.at(i).getValue() == "var")
		{
			variables.push_back(tokens.at(i + 1).getValue());
		}
	}
	cout << variables.size();
	//Check if variables are all declared
	for (int i = 0; i < tokens.size(); i++)
	{
		int arrayValue = 0;
		bool temp = true;

		if (!((tokens.at(i).getValue()[arrayValue] >= 'a' && tokens.at(i).getValue()[arrayValue] <= 'z')
			|| (tokens.at(i).getValue()[arrayValue] >= 'A' && tokens.at(i).getValue()[arrayValue] <= 'Z')
			|| tokens.at(i).getValue()[arrayValue] == '_'))
			temp = false;

		for (int counter = 1; counter < tokens.at(i).getValue().length(); ++counter)
		{
			if (!((tokens.at(i).getValue()[counter] >= 'a' && tokens.at(i).getValue()[counter] <= 'z')
				|| (tokens.at(i).getValue()[counter] >= 'A' && tokens.at(i).getValue()[counter] <= 'Z')
				|| (tokens.at(i).getValue()[counter] >= '0' && tokens.at(i).getValue()[counter] <= '9')
				|| tokens.at(i).getValue()[counter] == '_'))
				temp = false;
		}

		if (temp)
		{
			for(string key: variables)
			{
				if (key != tokens.at(i).getValue() && tokens.at(i).getValue() != "var" && tokens.at(i).getValue() != "input" && tokens.at(i).getValue() != "output")
				{
					this->result += "\nError " + tokens.at(i).getValue() + " is not declared";
				}
			}
		}

	}
	
	
	//Compare if the values of the variables is integer
	for (int i = 0; i < tokens.size(); i++)
	{
		for (string key : variables)
		{
			if (key == tokens.at(i).getValue())
			{
				if (tokens.at(i + 1).getValue() == "=")
				{
					bool temp = true;
					for (int counter = 0; counter < tokens.at(i + 2).getValue().length(); ++counter)
						if (!(tokens.at(i + 2).getValue()[counter] >= '0' && tokens.at(i + 2).getValue()[counter] <= '9'))
							temp = false;
					if (!temp) {
						this->result += "\nError " + tokens.at(i).getValue() + " value is not an integer";
					}
				}
			}
		}
	}
	
	
}

string TypeCheck::getResult()
{
	return this->result;
}
