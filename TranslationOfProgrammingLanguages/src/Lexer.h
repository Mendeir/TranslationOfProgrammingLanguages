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

    public:
    //Constructor and Destructor
    Lexer(string fileName);

    //Methods
    void retrieveFile();
    void displayCode();
    void tokenize();
    bool isKeyword(string givenToken);
    bool isVariable(string givenToken);
    bool isComment(string givenToken);
    bool isOperator(string givenToken);
    bool isNumericLiteral(string givenToken);
    void fillOperators();
    void fillKeywords();
    void addToken(string givenType, string givenValue);
    void displayTokens();


    //Getter and Setter

};

#endif 