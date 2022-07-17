#include "Token.h"

Token::Token(string type, string value)
{
	this->type = type;
	this->value = value;
	lineNumber = 0;
	columnNumber = 0;
}

Token::Token(string type, string value, int lineNumber, int columnNumber)
{
	this->type = type;
	this->value = value;
	this->lineNumber = lineNumber;
	this->columnNumber = columnNumber;
}

string Token::getType()
{
	return this->type;
}

string Token::getValue()
{
	return this->value;
}

int Token::getLineNumber()
{
	return this->lineNumber;
}

int Token::getColumnNumber()
{
	return this->columnNumber;
}