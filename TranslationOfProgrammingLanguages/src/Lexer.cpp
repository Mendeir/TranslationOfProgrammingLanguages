#include "Lexer.h"
#include <iostream>
#include <fstream>

using namespace std;

//***************************
//*	     CONSTRUCTOR        *
//***************************
Lexer::Lexer(string fileName)
{
    isWithinComment = false;
    isEndOfLine = false;
    isEndOfWord = false;
    isBlockComment = false;
    isWithinLiteral = false;
    this->fileName = fileName;
    fillOperators();
    fillKeywords();
}

//***************************
//*		   METHODS          *
//***************************
void Lexer::retrieveFile()
{
    fstream codeFile;

    codeFile.open(fileName, ios::in);

    if (!codeFile) {
        cerr << "File not found!";
        code = "";
    }

    string fileLine = "";

    while (getline(codeFile, fileLine)) {
        code += fileLine + ' ';
    }


}

void Lexer::displayCode()
{
    cout << code << '\n';
}



void Lexer::tokenize()
{
    int codeLength = code.length();
    int counter = 0;
    string subString = "";

    while (counter < codeLength)
    {
        string type;
        
        if (code[counter] == ';') 
            isEndOfLine = true;
        else
            isEndOfLine = false;

        if (code[counter] == ' ')
            isEndOfWord = true;
        else
            isEndOfWord = false;

        string s;
        s += code[counter];

        if (isOperator(s) && isWithinLiteral)
        {
            isEndOfWord = true;
        }

        if (!isEndOfLine && !isEndOfWord)
            subString += code[counter];

        if (isComment(subString))
        {
            addToken("COMMENT", subString);
            subString = "";
            ++counter;
            continue;
        }
        
        if (isWithinComment) 
        {
            //subString += code[counter];
            ++counter;
            continue;
        }

        if (isKeyword(subString))
        {
            addToken("KEYWORD", subString);
            subString = "";
            ++counter;
            continue;
        }

        if (isVariable(subString))
        {
            addToken("VARIABLE", subString);
            subString = "";
            ++counter;
            continue;
        }
        
        if (isOperator(subString))
        {
            addToken("OPERATOR", subString);
            subString = "";
            ++counter;
            continue;
        }

        if (isNumericLiteral(subString))
        {
            addToken("LITERAL", subString);
            subString = "";

            if (isOperator(s))
            {
                addToken("OPERATOR", s);
                s = "";
            }

            ++counter;
            continue;
        }
        
        
        ++counter;


    }
}

bool Lexer::isKeyword(string givenToken)
{
    for (string keyword : keywords)
        if (keyword == givenToken)
            return true;
    
    return false;
}

bool Lexer::isVariable(string givenToken)
{
    int arrayValue = 0;

    if (givenToken == "")
        return false;

    if (!(givenToken[givenToken.length() - 1] == ' ' || isEndOfLine || isEndOfWord))
    {
        isEndOfWord = false;
        isEndOfLine = false;
        return false;
    }

    if (!((givenToken[arrayValue] >= 'a' && givenToken[arrayValue] <= 'z')
        || (givenToken[arrayValue] >= 'A' && givenToken[arrayValue] <= 'Z')
        || givenToken[arrayValue] == '_'))
        return false;

    for (int counter = 1; counter < givenToken.length(); ++counter) 
    {
        if (!((givenToken[counter] >= 'a' && givenToken[counter] <= 'z')
            || (givenToken[counter] >= 'A' && givenToken[counter] <= 'Z')
            || (givenToken[counter] >= '0' && givenToken[counter] <= '9')
            || givenToken[counter] == '_' || givenToken[counter] == ';'))
            return false;
    }

    return true;
}

bool Lexer::isComment(string givenToken)
{
    for (int counter = 0; counter < givenToken.length(); ++counter) 
    {
        if (isWithinComment && isEndOfLine && !isBlockComment) {
            isWithinComment = false;
            isEndOfLine = false;
            return true;
        }

        if (isBlockComment && givenToken[counter] == '*' && givenToken[counter + 1] == '/') {
            isBlockComment = false;
            isWithinComment = false;
            return true;
        }

        if (givenToken[counter] == '/' && givenToken[counter + 1] == '/')
            isWithinComment = true;

        if (givenToken[counter] == '/' && givenToken[counter + 1] == '*')
        {
            isWithinComment = true;
            isBlockComment = true;
        }
        
        if (givenToken[counter + 1] == ';')
            isEndOfLine = true;
    }

    return false;
}

bool Lexer::isOperator(string givenToken)
{
    for (string op : operators)
        if (op == givenToken)
            return true;

    return false;
}

bool Lexer::isNumericLiteral(string givenToken)
{
    if (givenToken >= "0" && givenToken <= "9")
        isWithinLiteral = true;

    if (!isEndOfLine && !isEndOfWord)
        return false;

    if (givenToken == " " || givenToken == "")
        return false;

    for (int counter = 0; counter < givenToken.length(); ++counter)
        if (!(givenToken[counter] >= '0' && givenToken[counter] <= '9'))
            return false;

    isWithinLiteral = false;
    return true;
}

void Lexer::fillOperators()
{
    operators.push_back("+");
    operators.push_back("-");
    operators.push_back("*");
    //operators.push_back("/");
    operators.push_back("=");
    operators.push_back("(");
    operators.push_back(")");
}

void Lexer::fillKeywords()
{
    keywords.push_back("var");
    keywords.push_back("input");
    keywords.push_back("output");
}

void Lexer::addToken(string givenType, string givenValue)
{
    tokens.push_back(Token(givenType, givenValue));
}

void Lexer::displayTokens()
{
    for (Token token : tokens)
    {
        cout << "Type: " << token.getType() << '\n';
        cout << "Value: " << token.getValue() << '\n';
        cout << '\n';
    }
}
