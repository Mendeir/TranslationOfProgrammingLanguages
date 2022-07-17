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
    int index;
    vector <Token> code;
    map<string, int> variables;

public:
    //Constructor and Destructor
    Parser(vector <Token> tokens);

    //Methods
    void checkCurrent();
    string nextType(int);
    void match();
    void nextToken();
    void breakParse();
    void syntaxAnalyzer();
    int solvExpr(vector <Token> expression);
    void endCode();

};
#endif