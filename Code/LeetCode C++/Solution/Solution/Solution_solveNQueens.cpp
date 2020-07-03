#include "Solution_solveNQueens.h"

Solution_solveNQueens::Solution_solveNQueens()
{
}

void Solution_solveNQueens::RunTest()
{
	int n = 4;
	solveNQueens(n);
	int index = 0;
	for(vector<vector<string>>::iterator it = ret.begin();it!=ret.end();it++)
	{
		for(vector<string>::iterator i=it->begin();i!=it->end();i++)
		{
			cout << *i << endl;

		}
		cout << endl;
	}
}

vector<vector<string>> Solution_solveNQueens::solveNQueens(int n)
{
	string line(n, '.');
	solveNQueens(line, 0, n);
	return ret;
}

void Solution_solveNQueens::solveNQueens(string& line, int row, int n)
{
	if (tmp.size() == n)
	{
		ret.push_back(tmp);
		return;
	}
	for(int i =0;i<n;++i)
	{
		if(checkAll(row, i, n))
		{
			line[i] = 'Q';
			tmp.push_back(line);
			line[i] = '.';
			solveNQueens(line, row + 1, n);
			tmp.pop_back();
		}
	}
}

bool Solution_solveNQueens::checkAll(int row, int col, int n)
{
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)//左上方
	{
		if (tmp[i][j] == 'Q')
			return false;
	}
	for (int i = row - 1; i >= 0; --i)//正上方
	{
		if (tmp[i][col] == 'Q')
			return false;
	}
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)//右上方
	{
		if (tmp[i][j] == 'Q')
			return false;
	}
	return true;
}
