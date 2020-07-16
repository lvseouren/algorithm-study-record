//https://leetcode-cn.com/problems/daily-temperatures/
//请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//
//例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
//
//提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
#pragma once
#include <vector>
#include <stack>
#include "SolutionBase.h"
using namespace std;

class Solution_dailyTemperatures:SolutionBase {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> st;
		int cnt = T.size();
		vector<int> nextIndexTable(cnt, -1);
		for(int i = 0;i<cnt;i++)
		{
			while(!st.empty()&&T[i]>T[st.top()])
			{
				nextIndexTable[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		for(int i = 0;i<cnt;i++)
		{
			nextIndexTable[i] = nextIndexTable[i]>0? nextIndexTable[i] - i:0;
		}
		return nextIndexTable;
	}

	void RunTest()
	{
		RunTestCase({ 73, 74, 75, 71, 69, 72, 76, 73 });
	}

	void RunTestCase(vector<int> input)
	{
		vector<int> ret = dailyTemperatures(input);
		vecPrinter->print(ret);
	}
};