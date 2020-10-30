//632. 最小区间
//你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
//
//我们定义如果 b - a < d - c 或者在 b - a == d - c 时 a < c，则区间[a, b] 比[c, d] 小。

#pragma once
#include "SolutionBase.h"
class Solution_smallestRange :SolutionBase {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) 
	{

	}

	void RunTest()
	{
		RunTestCase();
	}

	void RunTestCase()
	{
		cout << "Input:" << endl;
		//cout << "Output:"<< smallestRange() << endl << endl;
	}
};