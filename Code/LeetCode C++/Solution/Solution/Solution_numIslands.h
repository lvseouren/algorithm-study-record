#pragma once
#include <vector>
using namespace std;

class Solution_numIslands {
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int nums = 0;
		
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					if (!checkLeftOrUpIsIsland(grid, i, j))
					{
						nums++;
					}
				}
			}
		}
		return nums;
	}

	bool checkLeftOrUpIsIsland(vector<vector<char>>& grid, int i, int j)
	{
		if (i == 0)
		{
			if (j == 0)
				return false;
			else
				return grid[i][j - 1] == '1';
		}
		else
		{
			if (j == 0)
				return grid[i - 1][j] == '1';
			else
				return grid[i - 1][j] == '1' || grid[i][j - 1] == '1';
		}
	}

	void RunTest()
	{
		vector<vector<char>> input = { {'1', '1', '1', '1', '0'},{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'} };
		RunTestCase(input);
		input = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
		RunTestCase(input);
		input = { {'1','1','1'},{'0','1','0'},{'1','1','1'} };
		RunTestCase(input);
	}

	void RunTestCase(vector<vector<char>> grid)
	{
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				cout << grid[i][j] << ',';
			}
			cout << endl;
		}
		int ret = numIslands(grid);
		cout << "µºÓì¸öÊý:" << ret << endl << endl;
	}
};