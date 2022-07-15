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
    isBlockComment = false;
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
        
        if(fileLine != " " && fileLine != "" && fileLine != "\n"){
            code += fileLine;
            LineCodes.push_back(code);
        }
        //code += fileLine + '\n';
        code = "";
    }


}

void Lexer::displayCode()
{
    cout << code << '\n';
}

int Lexer::getCodeLength(){

    return code.length();
}

vector<string> Lexer::getLineCodes(){
    return LineCodes;
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

    if (!((givenToken[arrayValue] >= 'a' && givenToken[arrayValue] <= 'z')
        || (givenToken[arrayValue] >= 'A' && givenToken[arrayValue] <= 'Z')
        || givenToken[arrayValue] == '_'))
        return false;

    for (int counter = 1; counter < givenToken.length(); ++counter) 
    {
        if (!((givenToken[counter] >= 'a' && givenToken[counter] <= 'z')
            || (givenToken[counter] >= 'A' && givenToken[counter] <= 'Z')
            || (givenToken[counter] >= '0' && givenToken[counter] <= '9')
            || givenToken[counter] == '_'))
            return false;
    }

    return true;
}

bool Lexer::isComment(string givenToken)
{
    for (int counter = 0; counter < givenToken.length(); ++counter) 
    {
        if (isWithinComment && isEndOfLine && !isBlockComment)
            return true;

        if (isBlockComment && givenToken[counter] == '*' && givenToken[counter + 1] == '/')
            return true;

        if (givenToken[counter] == '/' && givenToken[counter + 1] == '/')
            isWithinComment = true;

        if (givenToken[counter] == '/' && givenToken[counter + 1] == '*')
        {
            isWithinComment = true;
            isBlockComment = true;
        }
        
        if (givenToken[counter] == ';')
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
    for (int counter = 0; counter < givenToken.length(); ++counter)
        if (!(givenToken[counter] >= '0' && givenToken[counter] <= '9'))
            return false;
   
    return true;
}

bool Lexer::isTerminator(string givenToken){
    const string TERMNINATOR = ";";

    if(givenToken == TERMNINATOR)
        return true;
    
    return false;
}
void Lexer::fillOperators()
{
    operators.push_back("+");
    operators.push_back("-");
    operators.push_back("*");
    operators.push_back("/");
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

