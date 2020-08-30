#pragma once
#include "SolutionBase.h"
class Contest_204_2:SolutionBase
{
public:
	int getMaxLen(vector<int>& nums) 
	{
		int cnt = nums.size();
		int maxLen = 0;
		int fushuCnt = 0;
		int preZero = 0;
		vector<int> dp(cnt + 1, 0);
		for (int j = 1; j <= cnt; ++j)
		{
			fill(dp.begin(), dp.end(), 0);
			for (int i = j; i <= cnt; ++i)
			{
				if (nums[i - 1] == 0)
				{
					dp[i] = 0;
					fushuCnt = 0;
					preZero = i;
				}
				else if (nums[i - 1] > 0)
				{
					dp[i] = max(dp[i], dp[i - 1] + 1);
				}
				else
				{
					fushuCnt++;
					if (fushuCnt % 2 == 0)
					{
						dp[i] = max(dp[i], i - preZero);
					}
				}
				maxLen = max(maxLen, dp[i]);
			}
		}
		return maxLen;
	}

	void RunTest()
	{
	/*	RunTestCase({ 1, -2, -3, 4 });
		RunTestCase({ 0,1,-2,-3,-4 });
		RunTestCase({ -1,-2,-3,0,1 });
		RunTestCase({ -1,2 });
		RunTestCase({ 1,2,3,5,-6,4,0,10 });
		RunTestCase({ 0,-1,-2,-3,-4 });
		RunTestCase({ -16,0,-5,2,2,-13,11,8 });
		RunTestCase({ 9,10,1,0,19,20,-28,30,-12,20,11,-8,7,21,-26 });*/
		RunTestCase({ 5, -20, -20, -39, -5, 0, 0, 0, 36, -32, 0, -7, -10, -7, 21, 20, -12, -34, 26, 2 });
		
	}

	void RunTestCase(vector<int> nums)
	{
		vecPrinter->print(nums);
		cout << "output:" << getMaxLen(nums) << endl << endl;
	}
};
