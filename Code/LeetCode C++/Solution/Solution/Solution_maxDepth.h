#pragma once
#include "TreeNode.h"

class Solution_maxDepth
{
public:
	Solution_maxDepth();
	int maxDepth(TreeNode* root);
	int maxDepth_iterate_dfs(TreeNode* root);
	int maxDepth_iterate_bfs(TreeNode* root);
};

