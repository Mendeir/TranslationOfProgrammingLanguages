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
    bool isEndOfWord;
    bool isWithinLiteral;
    vector <string> keywords;
    vector <string> operators;
    vector <Token> tokens;

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
    void tokenize();
    void addToken(string givenType, string givenValue, int lineNumber, int columnNumber);
    void displayTokens();
    void fillOperators();
    void fillKeywords();

    //Getter and Setter
    vector <Token> getTokens();
};

#endif 