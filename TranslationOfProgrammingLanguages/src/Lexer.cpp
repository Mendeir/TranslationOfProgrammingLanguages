#include "Lexer.h"
#include <iostream>
#include <fstream>

using namespace std;

//***************************
//*	     CONSTRUCTOR        *
//***************************
Lexer::Lexer(string fileName)
{
    this->fileName = fileName;
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
        code += fileLine + " ";
    }


}

void Lexer::processFile()
{

}

void Lexer::displayCode()
{
    cout << code << '\n';
}