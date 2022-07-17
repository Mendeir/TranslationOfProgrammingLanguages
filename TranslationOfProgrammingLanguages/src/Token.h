#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

using namespace std;

class Token
{
	private:
	string type;
	string value;
	int lineNumber;
	int columnNumber;

	public:
	Token(string type, string value);
	Token(string type, string value, int lineNumber, int columnNumber);
	string getType();
	string getValue();
	int getLineNumber();
	int getColumnNumber();
};

#endif
