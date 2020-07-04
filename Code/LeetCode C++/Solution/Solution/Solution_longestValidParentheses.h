#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;
class Solution_longestValidParentheses
{
public:
	Solution_longestValidParentheses();
	int longestValidParentheses(string s);
	void RunTest();
private:
	void RunTestCase(string s);
	bool CheckValid(string s, int index);
	void backtrack(string s, int start);
	string curStr;
	int curMaxLength;
};

