#pragma once
#include "SolutionBase.h"
class Solution_runningSum :SolutionBase {
public:
	vector<int> runningSum(vector<int>& nums) {
		int length = nums.size();
		for(int i = 1;i<length;++i)
		{
			nums[i] = nums[i - 1] + nums[i];
		}
		return nums;
	}

	void RunTest()
	{
		vector<int> nums = { 1,2,3,4 };
		RunTestCase(nums);
		vector<int> nums = { 1,1,1,1 };
		RunTestCase(nums);
	}

	void RunTestCase(vector<int>& nums)
	{
		cout << "Input:" << endl;
		auto output = runningSum(nums);
		vecPrinter->print(output);
	}
};