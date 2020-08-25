#pragma once
#include "SolutionBase.h"
class Solution_canJump:SolutionBase {
public:
	bool canJump(vector<int>& nums) 
	{
		bool ret = false;
		int cnt = nums.size();
		int curMaxReachableIndex = 0;
		for (int i = 0; i < cnt; ++i)
		{
			if (i<=curMaxReachableIndex)
			{
				curMaxReachableIndex = max(curMaxReachableIndex, i + nums[i]);
				if (curMaxReachableIndex >= cnt - 1)
				{
					ret = true;
					break;
				}
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 2,3,1,1,4 });
		RunTestCase({ 3,2,1,0,4 });
		RunTestCase({ 0,2,3 });
		RunTestCase({ 0 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << endl;
		cout << (canJump(nums) ? "可以到达最后一个位置" : "不能到达最后一个位置") << endl << endl;
	}
};