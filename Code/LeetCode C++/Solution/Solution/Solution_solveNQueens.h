#pragma once
#include <vector>
#include <string>
#include "SolutionBase.h"

using namespace std;

class Solution_solveNQueens:SolutionBase
{
public:
	Solution_solveNQueens();
	vector<vector<string>> solveNQueens(int n);
	void RunTest();
	bool checkAll(int row, int col, int n);
private:
	void solveNQueens(string& line, int row, int n);
	vector<vector<string>> ret;
	vector<string> tmp;
};

