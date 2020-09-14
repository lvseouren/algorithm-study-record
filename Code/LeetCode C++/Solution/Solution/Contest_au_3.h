#pragma once
#pragma once
#include "SolutionBase.h"
class Contest_au_3 :SolutionBase
{
public:
	int minimumOperations(string s) 
	{
		int n = s.size();
		vector<vector<int>> f(n, vector<int>(3));
		f[0][0] = (s[0] == 'r' ? 0 : 1);
		for (int i = 1; i < n; ++i) {
			f[i][0] = f[i - 1][0] + (s[i] == 'r' ? 0 : 1);
			f[i][1] = f[i - 1][0] + (s[i] == 'y' ? 0 : 1);
			if (i > 1) {
				f[i][1] = min(f[i][1], f[i - 1][1] + (s[i] == 'y' ? 0 : 1));
				f[i][2] = f[i - 1][1] + (s[i] == 'r' ? 0 : 1);
			}
			if (i > 2) {
				f[i][2] = min(f[i][2], f[i - 1][2] + (s[i] == 'r' ? 0 : 1));
			}
		}
		return f[n - 1][2];

	}

	void RunTest()
	{
		RunTestCase("yry");//3
		RunTestCase("rrryyyrryyyrr");//2
		RunTestCase("ryr");//0
		RunTestCase("yryry");//2
		RunTestCase("rrr");//1
		RunTestCase("yyy");//2
		RunTestCase("ryyryyrryyrryr");//3
	}

	void RunTestCase(string leaves)
	{
		cout << "Input:";
		int ret = minimumOperations(leaves);
		cout << "Output:" <<ret<< endl << endl;
	}
};