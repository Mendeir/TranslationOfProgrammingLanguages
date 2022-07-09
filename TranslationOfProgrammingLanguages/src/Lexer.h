#ifndef _LEXER_H_
#define _LEXER_H_

#include <string>

using namespace std;

class Lexer
{
    private:
    string fileName;
    string code;

    public:
    //Constructor and Destructor
    Lexer(string fileName);

    //Methods
    void retrieveFile();
    void processFile();
    void displayCode();


    //Getter and Setter

};

#endif 