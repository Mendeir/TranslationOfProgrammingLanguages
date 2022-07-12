#include "Token.h"

Token::Token()
{
	type = "none";
	value = "none";
}

string Token::getType()
{
	return this->type;
}

string Token::getValue()
{
	return this->value;
}