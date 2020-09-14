#pragma once
#pragma once
#include "SolutionBase.h"
class Contest_au_1 :SolutionBase
{
public:
	int calculate(string s) 
	{
		int x = 1, y = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'A')
			{
				x = x * 2 + y;
			}
			else
			{
				y = y * 2 + x;
			}
		}
		return x + y;
	}

	void RunTest()
	{
		RunTestCase("");
		RunTestCase("AB");
		RunTestCase("A");
		RunTestCase("B");
	}

	void RunTestCase(string s)
	{
		cout << "Input:"<<s<<endl;
		int ret = calculate(s);
		cout << "Output:" <<ret<< endl << endl;
	}
};