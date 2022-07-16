#ifndef _LEXER_H_
#define _LEXER_H_

#include "Token.h"
#include <string>
#include <vector>

using namespace std;

class Lexer
{
    private:
    string fileName;
    string code;
    bool isWithinComment;
    bool isEndOfLine;
    bool isBlockComment;
    vector <string> keywords;
    vector <string> operators;
    vector <Token> tokens;
    vector <string> LineCodes;

    public:
    //Constructor and Destructor
    Lexer(string fileName);

    //Methods
    void retrieveFile();
    void displayCode();
    bool isKeyword(string givenToken);
    bool isVariable(string givenToken);
    bool isComment(string givenToken);
    bool isOperator(string givenToken);
    bool isNumericLiteral(string givenToken);
    bool isTerminator(string givenToken);
    void fillOperators();
    void fillKeywords();


    //Getter and Setter
    int getCodeLength();
    vector<string> getLineCodes();
};

#endif 