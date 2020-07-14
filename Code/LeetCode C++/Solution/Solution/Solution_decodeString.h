#pragma once
#include <string>
#include <stack>
using namespace std;
class Solution_decodeString
{
public:
	string decodeString(string s) 
	{

	}

	int toNumber(char c)
	{
		int charNum = (int)c;
		int charZero = (int)'0';
		int num = charNum - charZero;
		return num;
	}
};

