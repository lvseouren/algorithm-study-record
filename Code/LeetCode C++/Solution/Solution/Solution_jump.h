#pragma once
#include "SolutionBase.h"
class Solution_jump:SolutionBase {
public:
	int jump(vector<int>& nums) 
	{
		int cnt = nums.size();
		vector<int> dp(cnt, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = 1; j <= nums[i]; ++j)
			{
				if (i + j >= cnt)
					break;
				dp[i + j] = min(dp[i] + 1, dp[i+j]);
			}
		}
		return dp[cnt - 1];
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
		cout<<"最小跳跃数是：" << jump(nums)<< endl << endl;
	}
};