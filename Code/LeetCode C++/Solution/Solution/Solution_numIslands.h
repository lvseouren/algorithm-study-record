#pragma once
#include <vector>
using namespace std;

class Solution_numIslands {
public:
	map<int,bool> visited;
	int rowCnt;
	int colCnt;

	int numIslands(vector<vector<char>>& grid)
	{
		int ret = 0;
		rowCnt = grid.size();
		for(int i = 0;i< rowCnt;i++)
		{
			colCnt = grid[i].size();
			for(int j = 0;j< colCnt;j++)
			{
				ret += searchRecursive(grid, i, j, false);
			}
		}
		return ret;
	}

	int searchRecursive(vector<vector<char>>& grid, int row, int col, bool isPreIsland)
	{
		if (row < 0||col<0||row>=rowCnt||col>=colCnt||visited[row * colCnt + col])
			return 0;
		visited[row * colCnt + col] = true;
		if (grid[row][col] == '0')
			return 0;
		else
		{
			searchRecursive(grid, row + 1, col, true);
			searchRecursive(grid, row - 1, col, true);
			searchRecursive(grid, row, col+1, true);
			searchRecursive(grid, row, col-1, true);
			if (isPreIsland)
				return 0;
			else
				return 1;
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
		input = { {'1','0','1','1','0','1','1'} };
		RunTestCase(input);
	}

	void RunTestCase(vector<vector<char>> grid)
	{
		visited.clear();
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