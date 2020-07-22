#pragma once
#include <vector>
#include "SolutionBase.h"
#include <queue>
using namespace std;

class Solution_updateMatrix:SolutionBase {
public:
	int rowCnt;
	int colCnt;
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
	{
		vector<vector<int>> ret(matrix);

		rowCnt = matrix.size();
		colCnt = matrix[0].size();
		for(int i = 0;i<rowCnt;i++)
			for(int j = 0;j<colCnt;j++)
			{
				if (matrix[i][j] != 0)
				{
					for(int distance = 1;distance<max(rowCnt,colCnt);distance++)
					{
						if(CheckSurroundNum(matrix, i, j, distance))
						{
							ret[i][j] = distance;
							break;
						}
					}
				}
			}
		return ret;
	}

	vector<vector<int>> updateMatrix_bfs(vector<vector<int>>& matrix)
	{
		rowCnt = matrix.size();
		colCnt = matrix[0].size();

		queue<pair<int, int>> queues;
		for (int i = 0; i < rowCnt; i++)
			for (int j = 0; j < colCnt; j++)
				if (matrix[i][j] == 0)
					queues.push(pair<int, int>(i, j));
				else
					matrix[i][j] = -1;

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0,0,1,-1 };
		while(!queues.empty())
		{
			pair<int, int> point = queues.front();
			queues.pop();
			int x = point.first, y = point.second;
			for(int i = 0;i<4;i++)
			{
				int newX = x + dx[i], newY = y + dy[i];
				if(newX>=0&&newX<rowCnt&&newY>=0&&newY<colCnt&&matrix[newX][newY]==-1)
				{
					matrix[newX][newY] = matrix[x][y] + 1;
					queues.push(pair<int, int>(newX, newY));
				}
			}
		}
		return matrix;
	}

	bool CheckSurroundNum(vector<vector<int>>& matrix, int row, int col, int distance)
	{
		int rowStart = row - distance > 0 ? row - distance : 0;
		int rowEnd = row + distance < rowCnt - 1 ? row + distance : rowCnt - 1;
		int colStart = col - distance > 0 ? col - distance : 0;
		int colEnd = col + distance < colCnt - 1 ? col + distance : colCnt - 1;

		for(int i = rowStart;i<= rowEnd;i++)
		{
			for(int j = colStart;j <= colEnd;j++)
			{
				if(i==row&&j==col||abs(i-row)+abs(j-col)!=distance)
					continue;
				if (matrix[i][j] == 0)
					return true;
			}
		}
		return false;
	}

	void RunTest()
	{
		RunTestCase({ { 0,0,0 }, { 0,1,0 }, { 0,0,0 } });
		RunTestCase({ { 0,0,0 }, { 0,1,0 }, { 1,1,1 } });
	}

	void RunTestCase(vector<vector<int>> matrix)
	{
		vecPrinter->print(matrix);
		cout << endl;
		vector<vector<int>> output = updateMatrix_bfs(matrix);
		vecPrinter->print(output);
		cout << endl;
	}
};