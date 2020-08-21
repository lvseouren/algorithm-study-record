#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_minimumtotal
{
public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		vector<int> dp;
		for (int i = 0; i < triangle.size(); i++)
		{
			if (i > 0)
				dp[i] = dp[i - 1] + minRawNum(triangle[i]);
			else
				dp[i] = minRawNum(triangle[i]);
		}
	}

	int minRawNum(vector<int>& nums)
	{
		return 1;
	}

	void RunTest()
	{
		RunTestCase({ {2}, {3,4},{6,5,7 },{4,1,8,3} });
	}

	void RunTestCase(vector<vector<int>> triangle)
	{
		int output = minimumTotal(triangle);
		cout << "Êä³öÎª£º" << output << endl;
	}
};

