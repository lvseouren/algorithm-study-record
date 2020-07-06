#include "Solution_longestValidParentheses.h"

Solution_longestValidParentheses::Solution_longestValidParentheses()
{

}

void Solution_longestValidParentheses::RunTest()
{
	RunTestCase("()(())", 6);
	RunTestCase("()", 2);
	RunTestCase("((", 0);
	RunTestCase(")(", 0);
	RunTestCase("(()", 2);
	RunTestCase(")()())", 4);
	RunTestCase(")))))()()())", 6);
	RunTestCase(")))))()()())(((((((()", 6);
}


void Solution_longestValidParentheses::RunTestCase(string s, int expect)
{
	curMaxLength = 0;
	cout << "输入:" << s <<",预期输出："<<expect<< endl;
	//int ret = longestValidParentheses(s);
	int ret = longestValidParentheses_stack(s);
	cout << "输出:" << ret << endl;
}

int Solution_longestValidParentheses::longestValidParentheses(string s)
{
	int n = s.length();
	vector<int> dp(n, 0);
	for (int i = 1; i < n; ++i)
	{
		if(s[i] == ')')
		{
			if (s[i - 1] == '(')
				dp[i] = i>2?dp[i - 2] + 2:2;
			else if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='(')
			{
				if (i - dp[i - 1] > 2)
					dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
				else
					dp[i] = dp[i - 1] + 2;
			}
			curMaxLength = max(curMaxLength, dp[i]);
		}
	}
	return curMaxLength;
}

int Solution_longestValidParentheses::longestValidParentheses_stack(string s)
{
	stack<int> st;
	st.push(-1);
	for(int i = 0;i<s.length();i++)
	{
		if(s[i] == '(')
		{
			st.push(i);
		}else if(s[i] == ')')
		{
			st.pop();
			if (st.empty())
				st.push(i);
			else
				curMaxLength = max(curMaxLength, i - st.top());
		}
	}
	return curMaxLength;
}
