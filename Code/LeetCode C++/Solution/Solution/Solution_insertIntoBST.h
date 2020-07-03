#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_insertIntoBST:SolutionBase
{
public:
	Solution_insertIntoBST();
	TreeNode* insertIntoBST(TreeNode* root, int val);
	void RunTest();
private:
	void insertBST_DFS(TreeNode* root, int val);
	void RunTestCase(vector<int>, int);
};

