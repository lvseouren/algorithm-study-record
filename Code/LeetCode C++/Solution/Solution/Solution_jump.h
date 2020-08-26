#pragma once
#include "SolutionBase.h"
class Solution_jump:SolutionBase {
public:
	int jump(vector<int>& nums) 
	{
		int cnt = nums.size();
		vector<int> dp(max(cnt, 2), 0);
		dp[0] = 0;
		map<int, int> stepRight;
		stepRight[0] = 0;
		stepRight[1] = nums[0];

		for (int i = 1; i < cnt; ++i)
		{
			if (i > stepRight[dp[i - 1]])
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				dp[i] = dp[i - 1];
			}
			stepRight[dp[i]+1] = max(stepRight[dp[i]+1], i + nums[i]);
		}
		return dp[cnt - 1];
	}

	void RunTest()
	{
		RunTestCase({ 2,3,1,1,4 });
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