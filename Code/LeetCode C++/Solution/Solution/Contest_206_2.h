#pragma once
#include "SolutionBase.h"
class Contest_206_2:SolutionBase
{
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		int ret = 0;
		vector<int> visited(n, 0);
		for (int i = 0; i < pairs.size(); ++i)
			for (int j = 0; j < pairs.size(); ++j)
			{
				if (i == j)
					continue;
				int x = pairs[i][0];
				int y = pairs[i][1];
				int u = pairs[j][0];
				int v = pairs[j][1];
				if(visited[x]==0)
					if ((getDis(preferences, x, u) < getDis(preferences, x, y) && getDis(preferences, u, x) < getDis(preferences, u, v)) || (getDis(preferences, x, v) < getDis(preferences, x, y) && getDis(preferences, v, x) < getDis(preferences, v, u)))
					{
						visited[x] = 1;
						ret++;
					}
				if(visited[y]== 0)
					if ((getDis(preferences, y, u) < getDis(preferences, y, x) && getDis(preferences, u, y) < getDis(preferences, u, v)) || getDis(preferences, y, v) < getDis(preferences, y, x) && getDis(preferences, v, y) < getDis(preferences, v, u))
					{
						visited[y] = 1;
						ret++;
					}
			}

		return ret;
	}

	int getDis(vector<vector<int>>& preferences, int x, int y)
	{
		vector<int> preference = preferences[x];
		for (int i = 0; i < preference.size(); ++i)
		{
			if (preference[i] == y)
				return i;
		}
		return INT_MAX;
	}

	void RunTest()
	{
		RunTestCase(4, { {1, 2, 3},{3, 2, 0},{3, 1, 0},{1, 2, 0} }, { {0,1},{2,3} });
		RunTestCase(2, { {1},{0} }, { {0,1} });
		RunTestCase(4, { {1,3,2},{2,3,0},{1,3,0},{0,2,1} }, { {1,3},{0,2} });
	}

	void RunTestCase(int n, vector<vector<int>> preferences, vector<vector<int>> pairs)
	{
		int ret = unhappyFriends(n, preferences, pairs);
		cout << ret << endl;
	}
};