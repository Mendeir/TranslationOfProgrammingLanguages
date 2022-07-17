#include <string>
#include "Compiler.h"

using namespace std;

int main() 
{
	string fileName = "code.txt";
	Compiler compiler(fileName);
	compiler.compileCode();

	return 0;
}