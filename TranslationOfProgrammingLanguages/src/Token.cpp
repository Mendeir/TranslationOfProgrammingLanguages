#include "Token.h"

Token::Token(string type, string value)
{
	this->type = type;
	this->value = value;
}

string Token::getType()
{
	return this->type;
}

string Token::getValue()
{
	return this->value;
}