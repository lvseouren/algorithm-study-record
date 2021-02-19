#pragma once
#include "SolutionBase.h"
class Solution_subsetsWithDup :SolutionBase {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, int startIndex) 
	{
		result.push_back(path);
		for (int i = startIndex; i < nums.size(); i++) {
			// used[i - 1] == true，说明同一树支candidates[i - 1]使用过
			// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
			// 而我们要对同一树层使用过的元素进行跳过
			if (i > startIndex && nums[i] == nums[i - 1]) {
				continue;
			}
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
		result.clear();
		path.clear();
		sort(nums.begin(), nums.end()); // 去重需要排序
		backtracking(nums, 0);
		return result;
	}
public:
	void RunTest()
	{
		RunTestCase({1,2,2});
	}

	void RunTestCase(vector<int> nums)
	{
		result.clear();
		path.clear();
		cout << "Input:" << endl;
		vecPrinter->print(nums);
		cout<<endl << "Output:" << endl;
		vecPrinter->print(subsetsWithDup(nums));
	}
};