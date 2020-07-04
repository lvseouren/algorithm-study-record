#pragma once
#include "TreeNode.h"
#include <algorithm>

class Solution_maxPathSum
{
public:
	Solution_maxPathSum();
	int maxPathSum(TreeNode* root);
	void RunTest();
private:
	int calMaxPathSum(TreeNode* root);
	int curMaxSum;
};

