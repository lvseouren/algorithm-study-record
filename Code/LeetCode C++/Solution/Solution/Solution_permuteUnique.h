#pragma once
#include "SolutionBase.h"
class Solution_permuteUnique :SolutionBase {
	vector<vector<int>> result;
	vector<int> path;
	vector<int> visited;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		visited = vector<int>(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, 0);
		return result;
	}

	void backtrack(vector<int>& nums, int depth)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}

		for (int i = depth; i < nums.size(); ++i)
		{
			if(i>depth&&nums[i] == nums[i-1])
				continue;
			int num = nums[i];
			path.push_back(num);
			backtrack(nums, depth+1);
			path.pop_back();
		}
	}

	void RunTest()
	{
		RunTestCase({ 1,1,2 });
		RunTestCase({ 1,2,3 });
	}

	void RunTestCase(vector<int> nums)
	{
		result.clear();
		path.clear();
		cout << "Input:" << endl;
		vecPrinter->print(nums);
		cout << "Output:" << endl;
		vecPrinter->print(permuteUnique(nums));
		cout << endl;
	}
};