#pragma once
#include "functions.h"
#include <string>
#include <iostream>
#include <cstring>
using std::vector;
using std::string;
using std::cout;
void codeFormatter(string code)
{
	
}
int paranthesisState(string code,int state)
{
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == '(')
			state++;
		if (code[i] == ')')
			state--;
	}
	return state;
}
vector<string> removeBlanks (vector<string> code)
{
	bool ok;
	for (int i = 0; i < code.size(); i++) 
	{
		ok = false;
		for (int j = 0; j < code[i].size(); j++)
			if (code[i][j] != ' ')
				ok = true;
		if (ok == false) 
		{
			code.erase(code.begin() + i);
			i--;
		}
	}
	return code;
	

}
bool isfirstBracket(string code)
{
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] != ' ')
			if (code[i] == '{')
				return true;
			else return false;
	}
}
bool isfirstComment(string code)
{
	for (int i = 0; i < code.find("/*"); i++)
		if (code[i] != ' ')
			return false;
	return true;
}
bool islastComment(string code)
{
	int i = code.find("*/");
	if (i == code.size() - 2)
		return true;
	for (int i = code.find("*/")+2; i < code.size(); i++)
		if (code[i] != ' ')
			return false;
	return true;
			
}
int commentPos(string code)
{
	if (code.find("/*") != string::npos && code.find("*/") != string::npos)
	{
		return code.find("/*");
	}
	if (code.find("/*") != string::npos)
		return code.find("/*");
	if (code.find("*/") != string::npos)
		return code.find("\*");

}
int checkforComment(string code,int status)
{
	if (code.find("/*") != string::npos && code.find("*/") != string::npos)
		return 4;
	if (code.find("/*") != string::npos) {
		if (code.find("/*") == 0)
			return 0;
		return 1;
	}
		if (code.find("*/") != string::npos)
		{
			if (code.find("*/") == 0)
				return 2;
			return 3;
		}
	return status;
}
string addsemiColon(string code, string next, int isComment) //La comment daca e pus la final trebe verificat ce e inaintea lui
{
	string temp, temp1, tempc, tempc1,tempc2;
	int pos;
		if (isComment == 4)
		{
			if (code.find("/*") == 0 && code.find("*/") == code.length() - 2)
				return code;

			else
			{
				if (isfirstComment(code) == true)
				{
					tempc = code.substr(code.find("*/") + 2, code.length() - 1);
					tempc = addsemiColon(tempc, next, -1);
					if (code.find(tempc) != string::npos)
						return code;
					else
					{
						tempc1 = code.substr(code.find("/*"), code.find("*/") + 2);
						tempc1 += tempc;
						return tempc1;
					}
				}
				else if (islastComment(code) == true)
				{
					{
						tempc = code.substr(0, code.find("/*") - 1);
						tempc = addsemiColon(tempc, next, -1);
						if (code.find(tempc) != string::npos)
							return code;
						else
						{
							tempc1 = code.substr(code.find("/*"), code.find("*/") + 1);
							tempc += tempc1;
							return tempc;
						}
					}
				}
				else
				{
					tempc = code.substr(0, code.find("/*") - 1);
					tempc += " ";
					tempc += code.substr(code.find("*/") + 2, code.size());
					tempc2 = tempc;
					tempc = addsemiColon(tempc, next, -1);
					if (tempc2.find(tempc) != string::npos)
						return code;
					else
					{
						tempc.insert(code.find("/*"), code.substr(code.find("/*"), code.find("*/") - 2));
						return tempc;
					}
				}
			}
		}
		else if (isComment == 1)
		{
			tempc = code;
			tempc = tempc.substr(0, commentPos(code) - 1);
			tempc = addsemiColon(tempc, next, -1);
			if (code.find(tempc) != string::npos)
				return code;
			else
			{
				tempc1 = code.substr(commentPos(code) - 1, code.size());
				tempc += tempc1;
				return tempc;
			}

		}
		else if (isComment == 2)
		{
			tempc = code;
			if (code.back() == '*')
				return code;
			else
			{
				tempc = tempc.substr(commentPos(code) + 2, code.length());
				tempc = addsemiColon(tempc, next, -1);
				if (code.find(tempc) != string::npos)
					return code;
				else
				{
					tempc1 = code.substr(0, 1);
					tempc1 += tempc;
					return tempc1;
				}
			}
		}
		else if (isComment == 3)
		{
			if (code.back() == '/')
			{
				return code;
			}
			else
			{
				tempc = tempc.substr(commentPos(code) + 2, code.length());
				tempc = addsemiColon(tempc, next, -1);
				if (code.find(tempc) != string::npos)
					return code;
				else
				{
					tempc1 = code.substr(0, commentPos(code) + 1);
					tempc1 += tempc;
					return tempc1;
				}
			}
		}
		else if (isComment == 0)
			return code;

		if (code.size() > 0) 
		{
			if (code.back() == ';')
				return code;
			if (code.find("//") != string::npos)
			{
				if (code.find("//") == 0)
					return code;
				else
				{
					temp = code;
					pos = temp.find("//");
					temp = temp.substr(0, pos - 1);
					temp = addsemiColon(temp, next, isComment);
					if (code.find(temp) != string::npos)
					{
						return code;
					}
					else
					{
						temp1 = code.substr(pos - 1, code.size());

						temp += temp1;
						return temp;
					}
				}



			}
			if (code.find("do") != string::npos)
				return code;
			if (code.back() == '{' || code.back() == '}' || code.find("#include") != string::npos)
				return code;
			if (code.back() == ')')
				if (isfirstBracket(next) == true)
					return code;
			code.push_back(';');
		}
	return code;
}