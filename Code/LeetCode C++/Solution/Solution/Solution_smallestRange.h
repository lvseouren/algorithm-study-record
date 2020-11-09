//632. ��С����
//���� k �� �ǵݼ����� �������б��ҵ�һ�� ��С ���䣬ʹ�� k ���б��е�ÿ���б�������һ�������������С�
//
//���Ƕ������ b - a < d - c ������ b - a == d - c ʱ a < c��������[a, b] ��[c, d] С��

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