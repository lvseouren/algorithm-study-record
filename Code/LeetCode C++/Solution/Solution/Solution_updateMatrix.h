#pragma once
#include <vector>
#include "SolutionBase.h"
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
					for(int distance = 1;distance<rowCnt;distance++)
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

	bool CheckSurroundNum(vector<vector<int>>& matrix, int row, int col, int distance)
	{
		int rowStart = row - distance;
		int rowEnd = row + distance;
		int colStart = col - distance > 0 ? col - distance : 0;
		int colEnd = col + distance < colCnt - 1 ? col + distance : colCnt - 1;

		for(int i = rowStart;i<= rowEnd;i++)
		{
			for(int j = colStart;j <= colEnd;j++)
			{
				if(i==row&&j==col||abs(i-row)+abs(j-col)>distance)
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
		vector<vector<int>> output = updateMatrix(matrix);
		vecPrinter->print(output);
		cout << endl;
	}
};