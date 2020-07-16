#pragma once
#include <vector>
using namespace std;

class Solution_numIslands {
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if (grid.empty())
			return 0;
		int i,j,ret = 0;
		int rowCnt = grid.size();
		int colCnt = grid[0].size();
		for(i = 0;i< rowCnt;++i)
		{
			for(j = 0;j< colCnt;++j)
			{
				if (grid[i][j] == '1')
				{
					ret++;
					searchRecursive(grid, i, j, rowCnt, colCnt);
				}
			}
		}
		return ret;
	}

	void searchRecursive(vector<vector<char>>& grid, int row, int col, int rowCnt, int colCnt)
	{
		if (grid[row][col] == '0')
			return;

		grid[row][col] = '0';
		if (row + 1 < rowCnt&&grid[row+1][col]=='1')
			searchRecursive(grid, row + 1, col, rowCnt, colCnt);
		if (row - 1 >= 0&&grid[row-1][col]=='1')
			searchRecursive(grid, row - 1, col, rowCnt, colCnt);
		if (col + 1 < colCnt&&grid[row][col+1]=='1')
			searchRecursive(grid, row, col + 1, rowCnt, colCnt);
		if (col - 1 >= 0&&grid[row][col-1]=='1')
			searchRecursive(grid, row, col - 1, rowCnt,colCnt);
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