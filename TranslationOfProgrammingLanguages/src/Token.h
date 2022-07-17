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
	string getType();
	string getValue();

};

#endif
