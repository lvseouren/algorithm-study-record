#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;
class Solution_longestValidParentheses
{
public:
	Solution_longestValidParentheses();
	int longestValidParentheses(string s);
	int longestValidParentheses_stack(string s);
	void RunTest();
private:
	void RunTestCase(string s, int);
	int curMaxLength;
};

