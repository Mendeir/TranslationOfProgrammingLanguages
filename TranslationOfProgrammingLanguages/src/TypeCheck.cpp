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
                if(lexer.isOperator(op)){
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
    cout << "VALUES __________________";
    for(auto i: splitStrings){
        cout << i << endl;
    }
    return tokens;
}


//For testing only REMOVE LATER
int main(){
    makeTokens();
}



