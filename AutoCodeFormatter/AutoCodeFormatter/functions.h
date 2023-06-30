#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
int paranthesisState(string code, int state);
vector<string> removeBlanks(vector<string> code);
void codeFormatter(std::string code);
string addsemiColon(string,string,int);
bool isfirstBracket(string);
int checkforComment(string code, int status);
int commentPos(string code);
