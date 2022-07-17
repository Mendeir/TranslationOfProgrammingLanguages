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
    int index; //index of current token parsed
    vector <Token> code; //ordered container for the program tokens
    map<string, int> variables; //<key, value>

public:
    //Constructor and Destructor
    Parser(vector <Token> tokens); //Parser constructor

    //Methods
    string nextType(int); //returns
    void nextToken(); //advances token parsing
    void breakParse(); //error triggered program exit
    void syntaxAnalyzer(); //body of parser; triggers beginning of parsing
    int solvExpr(vector <Token> expression); //simplification of expressions after the assignment operator
    void endCode(); //end of program code
    void output(Token token); //output to console

};
#endif