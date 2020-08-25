#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_minimumtotal
{
public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		int raw = triangle.size();
		vector<vector<int>> dp(raw,vector<int>(raw,0));
		
		int curMin = INT_MAX;
		for (int i = 0; i < raw; ++i)
		{
			int colCnt = triangle[i].size();
			for (int j = 0; j < colCnt; ++j)
			{
				if (i == 0)
					dp[i][j] = triangle[i][j];
				else
				{
					dp[i][j] = min(j>0?dp[i - 1][j - 1]:INT_MAX, j<colCnt-1?dp[i - 1][j]:INT_MAX) + triangle[i][j];
				}
				if (i == raw - 1)
					curMin = min(dp[i][j], curMin);
			}
		}
		return curMin;
	}

	void RunTest()
	{
		RunTestCase({ {2}, {3,4},{6,5,7 },{4,1,8,3} });
		RunTestCase({ {1}, {1,1},{1,2,1 },{1000,1000,2,2} });
		RunTestCase({ {1}, {1,1},{1,2,2 },{1,2,2,1},{1000,1000,2,2,2} });
		RunTestCase({{1}, {-2, -5}, {3, 6, 9}, {-1, 2, 4, -3}} );
		RunTestCase({ {-1}, {9, -2}, {0, 4, 5}, {7, 4, -4, -5}, {9, 6, 0, 5, 7}, {9, 2, -9, -4, 5, -2}, {-4, -9, -5, -7, -5, -5, -2}, {-9, 5, -6, -4, 4, 1, 6, -4}, {-4, 3, 9, -2, 8, 6, -9, -2, -2}, {7, -6, 9, 8, -4, 2, -4, -2, -1, -2}, {0, 3, 2, 4, 0, -6, 7, 6, 7, -5, 2}, {9, 0, -8, 6, 4, 6, 2, 5, -9, 9, -1, -6}, {6, -3, -4, -5, 0, 3, 3, 4, -6, -4, -7, 7, 3} });
	}

	void RunTestCase(vector<vector<int>> triangle)
	{
		int output = minimumTotal(triangle);
		cout << "Êä³öÎª£º" << output << endl<<endl;
	}
};

