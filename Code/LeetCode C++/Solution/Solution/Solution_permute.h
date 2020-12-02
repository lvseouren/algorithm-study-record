#pragma once
#include "SolutionBase.h"
class Solution_permute :SolutionBase {
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<int> visited = vector<int>(nums.size());
		vector<int> list;
		vector<vector<int>> ret;
		backtrack(nums, list, visited, ret);
		return ret;
	}

	void backtrack(vector<int>& nums, vector<int>& list, vector<int>& visited, vector<vector<int>>& ret)
	{
		if (list.size() == nums.size())
		{
			ret.push_back(list);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				list.push_back(nums[i]);
				backtrack(nums, list, visited, ret);
				list.pop_back();
				visited[i] = 0;
			}
		}
	}

	void RunTest()
	{
		RunTestCase({1,2,3});
		RunTestCase({  });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "----Input:" << endl;
		vecPrinter->print(nums);
		auto output = permute(nums);
		cout << "----Output:" << endl;
		vecPrinter->print(output);
		cout << endl;
	}
};