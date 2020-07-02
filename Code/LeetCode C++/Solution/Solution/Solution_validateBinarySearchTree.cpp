#include "Solution_validateBinarySearchTree.h"
#include <cstddef>

Solution_validateBinarySearchTree::Solution_validateBinarySearchTree()
{

}

bool Solution_validateBinarySearchTree::isValidBST(TreeNode* root)
{
	if (root == NULL)
		return true;
	bool ret = true;
	if (root->left)
		ret = ret && root->left->val < root->val && isValidBST(root->left);
	if (!ret)
		return ret;
	if (root->right)
		ret = ret && root->right->val > root->val && isValidBST(root->right);
	if (!ret)
		return ret;

	return ret;
}
