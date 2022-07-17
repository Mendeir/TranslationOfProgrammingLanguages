#ifndef _TYPECHECK_H_
#define _TYPECHECK_H_

#include "Lexer.h"
#include "Token.h"
#include <string>


using namespace std;

class TypeCheck 
{
	private:
		string result;

	public:
		TypeCheck();
		void checkTokens(vector <Token> tokens);
		string getResult();
		
};

#endif