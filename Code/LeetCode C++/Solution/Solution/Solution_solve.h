#pragma once
#include "SolutionBase.h"
class Solution_solve :SolutionBase {
public:
	long long solve(string str) 
	{
		stack<int> st;
		int curOprand = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '*')
			{
				int num2 = st.top();
				st.pop();
				int num1 = st.top();
				st.pop();
				st.push(doOperation(num1,num2,str[i]));
			}
			else if (str[i] == '#')
			{
				st.push(curOprand);
				curOprand = 0;
			}
			else
			{
				curOprand *= 10;
				curOprand += (str[i]-'0');
			}
		}

		return st.top();
	}

	long long doOperation(int num1, int num2, char operat)
	{
		if (operat == '*')
			return num1 * num2;
		else if (operat == '+')
			return num1 + num2;
		else
			return num1 - num2;
	}

	void RunTest()
	{
		//RunTestCase("12#3#+15#*12#3#+15#*+");
		RunTestCase("5#1#2#+4#*+3#-");
	}

	void RunTestCase(string str)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< solve(str) << endl << endl;
	}
};