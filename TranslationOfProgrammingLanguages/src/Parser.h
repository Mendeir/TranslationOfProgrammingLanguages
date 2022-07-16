#ifndef _PARSER_H_
#define _PARSER_H_

#include "Token.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

class Parser
{
private:
    string fileName;
    vector <Token> code;
    map<string, int> variables;

public:
    //Constructor and Destructor
    Parser(vector <Token> tokens);

    //Methods
    void checkCurrent();
    string checkNext(Token);
    void match();
    void nextToken();
    void breakParse();
    void syntaxAnalyzer(Token token);
};
#endif