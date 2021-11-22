#pragma once
#include "SolutionBase.h"
//https://leetcode-cn.com/problems/string-to-integer-atoi/
class Solution_Leyi_Atoi :SolutionBase {
public:
	int myAtoi(string s)
	{
		bool isStarted = false, isStoped =false, isReadSymbol = false;
		int symbol = 0;
		int i = 0;
		int n = s.length();
		int ret = 0;
		while(!isStoped&&i<n)
		{
			char c = s[i];
			if(!isStarted)
			{
				if(isReadSymbol)
				{
					if (isNumber(c))
					{
						ret = ret * 10 + (c - '0');
						isStarted = true;
					}
					else
						isStoped = true;
				}else
				{
					if (isSymbol(c))
						symbol = getSymbol(c);
					else if(isNumber(c))
					{
						ret = c - '0';
						symbol = 1;
						isStarted = true;
					}
				}
			}else
			{
				if (isNumber(c))
					ret = ret * 10 + (c - '0');
				else
					isStoped = true;

			}
			i++;
		}
		return 0;
	}

	int getSymbol(char c)
	{
		return c == '+' ? 1 : -1;
	}

	bool isNumber(char c)
	{
		return c >= '0' && c <= '9';
	}

	bool isSymbol(char c)
	{
		return c == '+' || c == '-';
	}

	void RunTest()
	{
		RunTestCase("42");
		RunTestCase("   -42");
		RunTestCase(" 4193 with words");
	}

	void RunTestCase(string s)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< myAtoi(s) << endl << endl;
	}
};