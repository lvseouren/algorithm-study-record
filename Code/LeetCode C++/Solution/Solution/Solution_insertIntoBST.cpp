#include "Solution_insertIntoBST.h"
#include <cstddef>

Solution_insertIntoBST::Solution_insertIntoBST()
{

}

TreeNode* Solution_insertIntoBST::insertIntoBST(TreeNode* root, int val)
{
	if (root == NULL)
	{
		root = new TreeNode(val);
		return root;
	}
	insertBST_DFS(root, val);
	return root;
}

void Solution_insertIntoBST::insertBST_DFS(TreeNode* root, int val)
{
	if (root == NULL)
		return;

	if (root->val > val)
		if (root->left)
			insertBST_DFS(root->left, val);
		else
			root->left = new TreeNode(val);
	else
		if (root->right)
			insertBST_DFS(root->right, val);
		else
			root->right = new TreeNode(val);
}