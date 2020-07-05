#include "Solution_longestValidParentheses.h"

Solution_longestValidParentheses::Solution_longestValidParentheses()
{

}

void Solution_longestValidParentheses::RunTest()
{
	RunTestCase("()(())");
	RunTestCase("()");
	RunTestCase("((");
	RunTestCase(")(");
	RunTestCase("(()");
	RunTestCase(")()())");
	RunTestCase(")))))()()())");
	RunTestCase(")))))()()())(((((((()");
}


void Solution_longestValidParentheses::RunTestCase(string s)
{
	curMaxLength = 0;
	cout << "ÊäÈë:" << s << endl;
	int ret = longestValidParentheses(s);
	cout << "Êä³ö:" << ret << endl;
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
