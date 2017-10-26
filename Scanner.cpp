#include <iostream>
#include <fstream>
using namespace std;
///////////////////////////////////
bool isSpecialCharacter(string x)
{return (x==";" ||x==")" ||x=="(" ||x=="{" ||x=="}");}
///////////////////////////////////
bool isIdentifier(string x)
{
	if (!isalpha(x[0])) {return false;}
	for (int i = 1; i < x.size(); i++)
	{ if (!isdigit(x[i]) && !isalpha(x[i])) {return false;} }
	return true;
}
/////////////////////////////////////
bool isKeyWord(string x)
{return (x=="int"||x=="if"||x=="void"||x=="main"||x=="float"||x=="for"||x=="while"||x=="do"||x=="else"||x=="return");}
/////////////////////////////////////
bool isOperator(string x)
{return (x=="+"||x=="++"||x=="+="||x=="-"||x=="--"||x=="-+"||x=="="||x=="=="||x==">"||x=="<"||x=="<>"||x=="!="||x=="*"||x=="**"||x=="/"||x=="%"||x=="*="||x=="/="||x==">="||x=="<=");}
/////////////////////////////////////
bool isConstDigit(string x)
{
	int z = 0;
	if (!isdigit(x[0])) { return false; }
	for (int i = 1; i < x.size(); i++)
	{
		if (x[i] != '.'){
			if (!isdigit(x[i])) {return false;}
		}else{z++;}
	}
    return z<2; 
}
/////////////////////////////////////
int main ()
{
	string s;
    ifstream input("test.txt");
    ofstream output("token.txt");
	while (!input.eof())
	{
		input >> s;
		if(isSpecialCharacter(s)){output << s << " <special character>"<< endl;
		}else if (isKeyWord(s)){output << s << " <key word>"<< endl;
		}else if (isConstDigit(s)){output << s << " <constant digit>"<< endl;
		}else if (isOperator(s)){output << s << " <operator>"<< endl;
		}else if (isIdentifier(s)){output << s << " <identifier>"<< endl;
		}else{output << s << " <NOT in Language>"<< endl;} 
	}		
	return 0;
}


