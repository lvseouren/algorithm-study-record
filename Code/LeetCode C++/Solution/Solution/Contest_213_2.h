#pragma once
#pragma once
#include "SolutionBase.h"
class Contest_213_2 :SolutionBase
{
public:
	int countVowelStrings(int n) 
	{
		int nums[5] = { 5,4,3,2,1 };
		int dp[5] = { 1,0,0,0,0 };
		for(int i = 1;i<n;++i)
		{
			dp[1] = dp[0] + dp[1];
			dp[2] = dp[1] + dp[2];
			dp[3] = dp[2] + dp[3];
			dp[4] = dp[3] + dp[4];
		}
		int sum = 0;
		for(int i = 0;i<5;++i)
		{
			sum += dp[i] * nums[i];
		}
		return sum;
	}


	void RunTest()
	{
		RunTestCase(1);
		RunTestCase(2);
		RunTestCase(33);
	}

	void RunTestCase(int n)
	{
		cout << "Input:n=" << n << endl;
		cout<<"output£º"<< countVowelStrings(n)<<endl;
	}
};