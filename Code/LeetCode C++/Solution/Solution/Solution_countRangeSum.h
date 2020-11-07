#pragma once
#include "SolutionBase.h"
class Solution_countRangeSum :SolutionBase {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) 
	{
		int len = nums.size();
		int cnt = 0;
		vector<vector<long long int>> dp(len, vector<long long int>(len));
		
		for(int i = 0;i<len;++i)
			for(int j = i;j<len;++j)
			{
				if (i == j)
					dp[i][j] = (long long int)nums[i];
				else
					dp[i][j] = dp[i][j - 1] + (long long int)nums[j];
				if (dp[i][j] >= (long long int)lower && dp[i][j] <= (long long int)upper)
					cnt++;
			}

		return cnt;
	}

	void RunTest()
	{
		RunTestCase({ -2,5,-1 }, -2, -2);
		RunTestCase({ -2,5,-1 }, -2, 2);
		RunTestCase({ -2,5,-1 }, -2, 3);
		RunTestCase({ -2147483648,-1,-3 }, -2, 2147483647);
	}

	void RunTestCase(vector<int> nums, int lower, int upper)
	{
		cout << "Input:" << endl;
		vecPrinter->print(nums);
		cout << "区间为[" << lower << "," << upper << "]" << endl;
		cout << "区间和在上述区间内的区间个数:"<< countRangeSum(nums, lower, upper) << endl << endl;
	}
};