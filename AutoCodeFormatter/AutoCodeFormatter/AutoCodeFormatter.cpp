#include <Windows.h>
#include "functions.h"
using std::string;
using std::vector;
using std::cin;
using std::getline;
int main()
{
	int lines;
	int paranthesisstate = 0;
	std::cin >> lines;
	std::cin.ignore();
	vector<string> code(lines);
	for (int i = 0; i < lines; i++)
		getline(cin, code[i]);
	system("cls");
	code = removeBlanks(code);
	lines = code.size();
	int status = -1;
	//for (int i = 0; i < lines; i++)
		//std::cout <<code[i]<<"-"<< code[i].length() << "\n";
	for (int i = 0; i < lines; i++)
	{
		paranthesisstate = paranthesisState(code[i], paranthesisstate);
		status=checkforComment(code[i], status);
		if (i == lines - 1)
		{
			if (paranthesisstate == 0)
				code[i] = addsemiColon(code[i], "kaksmsagmsmgkafa1123123", status);
		}
		else if (paranthesisstate == 0) 
				code[i]=addsemiColon(code[i], code[i + 1],status);
		if (status == 1)
			status = 0;
		else if (status == 2)
			status = -1;
		else if (status == 3)
			status = -1;
		else if (status == 4)
			status = -1;
	}
	for (int i = 0; i < lines; i++)
		std::cout << code[i] << "\n";

	
}