#include "Solution_maxDepth.h"

Solution_maxDepth::Solution_maxDepth()
{
}

int Solution_maxDepth::maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}