#pragma once
#pragma once
#include "SolutionBase.h"
class Contest_213_4 :SolutionBase
{
public:
	string kthSmallestPath(vector<int>& destination, int k) 
	{
		int h = destination[1];
		int v = destination[0];
		vector<vector<int>> dp = vector <vector<int>>(h+1, vector<int>(v+1));


		for(int i = 0;i<=h;++i)
		{
			for(int j = 0;j<=v;++j)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
				{
					int preJ = j - 1;
					int preI = i - 1;
					dp[i][j] = (preI > 0 ? dp[preI][j] : 1) + (preJ > 0 ? dp[i][preJ] : 1);
				}
			}
		}

		string ret;
		for(int i =0,imax=h+v;i<imax;++i)
		{
			if(h>0)
			{
				int o = dp[h-1][v];
				if(k>o)
				{
					ret += 'V';
					k -= o;
					v--;
				}else
				{
					ret += 'H';
					h--;
				}
			}
			else
			{
				ret += 'V';
				--v;
			}
		}
		return ret;
	}

	void RunTest()
	{
		//RunTestCase({ 2,3 }, 7);
		//RunTestCase({ 2,3 }, 1);
		RunTestCase({ 2,3 }, 2);
		RunTestCase({ 2,3 }, 3);
	}

	void RunTestCase(vector<int> destination, int k)
	{
		cout << "Input:";
		vecPrinter->print(destination);
		cout << "k=" << k << endl;
		cout << "Output:"<< kthSmallestPath(destination, k) << endl << endl;
	}
};