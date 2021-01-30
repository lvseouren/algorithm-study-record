#pragma once
#include "SolutionBase.h"
class Solution_subsets2 :SolutionBase {
	vector<vector<int>> ret;
	vector<int> path;
public:
	vector<vector<int>> subsets(vector<int>& nums) 
	{
		backtrack(nums, 0);	
		return ret;
	}

	void backtrack(vector<int>& nums, int depth)
	{
		ret.push_back(path);
		for (int i = depth; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);
			backtrack(nums, i + 1);
			path.pop_back();
		}
	}

	void RunTest()
	{
		RunTestCase({ 1,2,3 });
		RunTestCase({ 0 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "------------------------------------" << endl;
		cout << "input:";
		vecPrinter->print(nums);
		cout << endl;
		ret.clear();
		path.clear();
		subsets(nums);
		vecPrinter->print(ret);
	}
};