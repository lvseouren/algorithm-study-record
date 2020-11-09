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
		int rangeLeft = 0, rangeRight = INT_MAX;
		int size = nums.size();
		vector<int> next(size);

		auto cmp = [&](const int& u, const int& v) {
			return nums[u][next[u]] > nums[v][next[v]];
		};
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
		int minValue = 0, maxValue = INT_MIN;
		for (int i = 0; i < size; ++i) {
			pq.emplace(i);
			maxValue = max(maxValue, nums[i][0]);
		}

		while (true) {
			int row = pq.top();
			pq.pop();
			minValue = nums[row][next[row]];
			if (maxValue - minValue < rangeRight - rangeLeft) {
				rangeLeft = minValue;
				rangeRight = maxValue;
			}
			if (next[row] == nums[row].size() - 1) {
				break;
			}
			++next[row];
			maxValue = max(maxValue, nums[row][next[row]]);
			pq.emplace(row);
		}

		return { rangeLeft, rangeRight };
	}

	void RunTest()
	{
		RunTestCase({{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}} );
		RunTestCase({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}} );
		RunTestCase({{10, 10}, {11, 11}} );
		RunTestCase({{10}, {11}} );
		RunTestCase({{1}, {2}, {3}, {4}, {5}, {6}, {7}} );
	}

	void RunTestCase(vector<vector<int>> nums)
	{
		cout << "Output:"<< endl;
		vector<int> output = smallestRange(nums);
		vecPrinter->print(output);
	}
};