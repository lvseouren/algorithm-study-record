#pragma once
#include <vector>
using namespace std;

class Solution_numIslands {
public:
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
				ret += searchRecursive(grid, i, j);
			}
		}
		return ret;
	}

	int searchRecursive(vector<vector<char>>& grid, int row, int col)
	{
		if (grid[row][col] == '0')
			return 0;

		grid[row][col] = '0';
		if (row + 1 < rowCnt)
			searchRecursive(grid, row + 1, col);
		if (row - 1 >= 0)
			searchRecursive(grid, row - 1, col);
		if (col + 1 < colCnt)
			searchRecursive(grid, row, col + 1);
		if (col - 1 >= 0)
			searchRecursive(grid, row, col - 1);
		return 1;
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