#include "Solution_longestValidParentheses.h"

Solution_longestValidParentheses::Solution_longestValidParentheses()
{
	curStr.clear();
}

int Solution_longestValidParentheses::longestValidParentheses(string s)
{
	backtrack(s, 0);
	return curMaxLength;
}

void Solution_longestValidParentheses::RunTest()
{
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
	curStr.clear();
	cout << "ÊäÈë:" << s << endl;
	int ret = longestValidParentheses(s);
	cout << "Êä³ö:" << ret << endl;
}


bool Solution_longestValidParentheses::CheckValid(string s, int index)
{
	if (s.size() <= index)
		return false;

	string newStr = curStr + s[index];
	if (newStr.size() == 2)
		return newStr=="()";
	int i = newStr.find("((");
	int j = newStr.find("))");
	if (i >= 0 || j >= 0)
		return false;
	else
		return true;
}

void Solution_longestValidParentheses::backtrack(string s, int start)
{
	if (!CheckValid(s, start))
	{
		return;
	}else
	{
		if(curStr.size()%2 == 1)
			curMaxLength = max(curMaxLength, (int)curStr.size() + 1);
	}

	for(int i=start;i<s.size();i++)
	{
		curStr.push_back(s[i]);
		backtrack(s, i + 1);
		curStr.erase(0,1);
	}
}
