#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

using namespace std;

class Token
{
	private:
	string type;
	string value;

	public:
	Token();
	string getType();
	string getValue();

};

#endif
