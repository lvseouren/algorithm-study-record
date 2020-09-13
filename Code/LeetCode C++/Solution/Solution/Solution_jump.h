#pragma once
#include "SolutionBase.h"
class Solution_jump:SolutionBase {
public:
	int jump(vector<int>& nums) 
	{
		int cnt = nums.size();
		int rightMost = 0;
		int step = 0;
		int end = 0;
		for (int i = 0; i < cnt-1; ++i)
		{
			//if (rightMost>=i)
			{
				rightMost = max(rightMost, i + nums[i]);
				if (i == end)
				{
					end = rightMost;
					step++;
				}
			}
		}
		return step;
	}

	void RunTest()
	{
		RunTestCase({ 4,3,1,1,4 });
		RunTestCase({ 0 });
		RunTestCase({ 1 });
		RunTestCase({ 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << endl;
		cout<<"最小跳跃数是：" << jump(nums)<< endl << endl;
	}
};