#include "Lexer.cpp"
#include "Token.cpp"
#include <vector>
#include <string>
#include <ctype.h>
#include <cctype>
using namespace std;

//Checklist
// - separate string contents into words
// - use lexer functions to determine type
const char NEWLINE = 10;
const char TAB = 9;

vector<Token> makeTokens(){
    Lexer lexer("code.txt");
    
    vector<Token> tokens;
    vector<string> splitStrings;
    string subString = "";
    string op = "";
    lexer.retrieveFile();

    for(string lines: lexer.getLineCodes()){
        subString = "";
        for(int i = 0; i < lines.length(); i ++){
            if(isspace(lines[i])){
                if (subString != ""){
                    splitStrings.push_back(subString);
                    subString = "";
                }
            }
            if(isalpha(lines[i]) || isdigit(lines[i])){
                subString += lines[i];
            }else{
                op += lines[i];
                if(lexer.isOperator(op) || lexer.isTerminator(op)){
                    if(subString != ""){
                        splitStrings.push_back(subString);
                    }
                    
                    splitStrings.push_back(op);
                    subString = "";
                    op = "";
                }
                op = "";

                
            } 
        }

    }
    
    //remove later used for testing
    for(auto i: splitStrings){
        if(lexer.isKeyword(i)){
            tokens.push_back(Token(i, "KEYWORD"));
        }else if(lexer.isNumericLiteral(i)){
            tokens.push_back(Token(i, "NUMERIC"));
        }else if(lexer.isVariable(i)){
            tokens.push_back(Token(i,"VARIABLE"));
        }else if(lexer.isOperator(i)){
            tokens.push_back(Token(i,"OPERATOR"));
        }else if(lexer.isComment(i)){
            tokens.push_back(Token(i,"COMMENT"));
        }else if(lexer.isTerminator(i)){
            tokens.push_back(Token(i,"TERMINATOR"));
        }else{
            tokens.push_back(Token(i,"UNDEFINED"));
        }
    }

    return tokens;
}


//For testing only REMOVE LATER
int main(){
    vector<Token> t = makeTokens();
    for(auto token: t){
        cout << token.getType() << " " << token.getValue() << endl;
    }
}



