#pragma once
#include "SolutionBase.h"
class Solution_lengthOfLIS:SolutionBase {
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		int cnt = nums.size();
		if (cnt < 1)
			return 0;
		
		vector<int> dp(cnt, 1);
		int ret = 1;
		for(int i = 0;i<cnt;++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
					ret = max(ret, dp[i]);
				}
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 10,9,2,5,3,7,101,18 });
		RunTestCase({  });
		RunTestCase({ 1 });
		RunTestCase({10,22,9,33,21,50,41,60,80});
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:" << endl;
		vecPrinter->print(nums);
		cout << "output:" << lengthOfLIS(nums) << endl << endl;
	}
};