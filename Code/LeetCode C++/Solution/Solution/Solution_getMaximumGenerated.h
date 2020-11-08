#pragma once
#include "SolutionBase.h"
class Solution_getMaximumGenerated :SolutionBase {
public:
	int getMaximumGenerated(int n) 
	{
		if (n == 0)
			return 0;
		vector<int> nums(n+1,0);
		nums[0] = 0;
		nums[1] = 1;
		int ret = 1;
		for(int i = 2;i<=n;++i)
		{
			if (i % 2 == 0)
				nums[i] = nums[i / 2];
			else
				nums[i] = nums[i / 2] + nums[i / 2 + 1];
			ret = max(ret, nums[i]);
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase(4);
		RunTestCase(0);
		RunTestCase(1);
		RunTestCase(7);
		RunTestCase(2);
		RunTestCase(3);
	}

	void RunTestCase(int n)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< getMaximumGenerated(n) << endl << endl;
	}
};