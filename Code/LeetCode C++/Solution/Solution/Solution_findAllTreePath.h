#pragma once
#include <vector>
#include "TreeNode.h"
#include "SolutionBase.h"

class Solution_findAllTreePath:SolutionBase
{
public:
	Solution_findAllTreePath();
	~Solution_findAllTreePath();
	void findAllTreePath(TreeNode* root);
	void RunTest();
private:
	vector<vector<int>>* pathRet;
	vector<int>* curPath;
};

