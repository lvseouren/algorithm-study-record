#pragma once
#include "SolutionBase.h"
#include <algorithm>
//https://leetcode-cn.com/problems/string-to-integer-atoi/

class Solution_Leyi_Atoi :SolutionBase {
public:
	int myAtoi(string s)
	{
		bool isStarted = false, isStoped =false, isReadSymbol = false;
		int symbol = 0;
		int i = 0;
		int n = s.length();
		long long ret = 0;
		int maxNum = 2147483647;
		int minNum = -2147483648;
		while(!isStoped&&i<n)
		{
			char c = s[i];
			if(!isStarted)
			{
				if(isReadSymbol)
				{
					if (isNumber(c))
					{
						ret = evaluate(ret, c, symbol);
						isStarted = true;
					}
					else
						isStoped = true;
				}
				else
				{
					if (isSymbol(c))
					{
						symbol = getSymbol(c);
						isReadSymbol = true;
					}
					else if (isNumber(c))
					{
						ret = c - '0';
						symbol = 1;
						isReadSymbol = true;
						isStarted = true;
					}
					else
					{
						if (c != ' ')
							break;
					}
				}
			}else
			{
				if (isNumber(c))
					ret = evaluate(ret, c, symbol);
				else
					isStoped = true;

			}
			i++;
		}
		ret *= symbol;
		return ret;
	}

	long long evaluate(long long input, char c, int sign)
	{
		input = input * 10 + (c - '0');
		if (sign == 1)
			input = min(input, (long long)INT_MAX);
		else
			input = min(input, -((long long)INT_MIN));
		return input;
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
		//RunTestCase("42");
		//RunTestCase("   -42");
		//RunTestCase(" 4193 with words");
		//RunTestCase("words and 987");
		RunTestCase("-91283472332");
	}

	void RunTestCase(string s)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< myAtoi(s) << endl << endl;
	}
};