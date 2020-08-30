#pragma once
#include "SolutionBase.h"
class Contest_204_1:SolutionBase
{
public:
	bool containsPattern(vector<int>& arr, int m, int k) 
	{
		int cnt = arr.size();
		vector<int> dp(cnt, 0);
		for (int j = 0; j <= cnt - m; ++j)
		{
			int modeStart = j;
			int modeStop = j + m - 1;
			for (int i = m-1; i < cnt; ++i)
			{
				bool isFitMode = checkIsFitMode(arr, i - m + 1, i, modeStart, modeStop);
				if(isFitMode)
				{
					if (i - m >= 0)
						dp[i] = max(dp[i], dp[i - m] + 1);
					else
						dp[i] = 1;
				}
				else
				{
					dp[i] = 0;
				}


				if (dp[i] >= k)
					return true;
			}
		}
		return false;
	}

	bool checkIsFitMode(vector<int>& arr, int start, int stop, int modeStart, int modeStop)
	{
		for(int i=0;i<=stop-start;++i)
		{
			if (arr[start + i] != arr[modeStart + i])
				return false;
		}
		return true;
	}

	void RunTest()
	{
		RunTestCase({ 1,2,4,4,4,4 },1,3);
		RunTestCase({ 1,2,1,2,1,1,1,3 }, 2, 2);
		RunTestCase({ 1,2,1,2,1,3 }, 2, 3);
		RunTestCase({ 1,2,3,1,2 }, 2, 2);
		RunTestCase({ 2,2,2,2 }, 2, 3);
		RunTestCase({ 2,2 }, 1, 2);
		RunTestCase({ 2,2 }, 2, 2);
	}

	void RunTestCase(vector<int> arr, int m, int k)
	{
		cout << "Input:";
		vecPrinter->print(arr);
		cout << "m=" << m << ",k=" << k << endl;
		cout << "Output:" << (containsPattern(arr,m,k)?"yes":"no") << endl << endl;
	}
};