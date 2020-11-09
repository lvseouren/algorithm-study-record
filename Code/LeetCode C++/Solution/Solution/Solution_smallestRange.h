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
		vector <pair<int, int>> sortedList;
		for (int i = 0; i < nums.size(); ++i)
			for (int j = 0; j < nums[i].size(); ++j)
				sortedList.push_back({ nums[i][j], i });

		sort(sortedList.begin(), sortedList.end());

		int left = 0, right = 0, leftBorder = 0, rightBorder = INT_MAX;
		map<int, int> cntDict;
		int containGroup = 0;
		int desContainGroupCnt = nums.size();
		while (right < sortedList.size())
		{
			int groupId = sortedList[right].second;
			
			if (cntDict.count(groupId)==0)
			{
				cntDict[groupId] = 1;
				containGroup++;
			}
			else
			{
				cntDict[groupId]++;
			}

			if (desContainGroupCnt == containGroup)
			{
				while (cntDict[sortedList[left].second] > 1)
				{
					cntDict[sortedList[left].second]--;
					left++;
				}
				int minInWindow = sortedList[left].first;
				int maxInWindow = sortedList[right].first;
				if (maxInWindow - minInWindow < rightBorder - leftBorder)
				{
					leftBorder = minInWindow;
					rightBorder = maxInWindow;
				}
			}
			right++;
		}
		return { leftBorder,rightBorder };
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