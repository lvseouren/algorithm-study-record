#pragma once
#include "TreeNode.h"
class Solution_insertIntoBST
{
public:
	Solution_insertIntoBST();
	TreeNode* insertIntoBST(TreeNode* root, int val);
private:
	void insertBST_DFS(TreeNode* root, int val);
};

