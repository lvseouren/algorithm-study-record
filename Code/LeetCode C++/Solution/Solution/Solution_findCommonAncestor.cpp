#include "Solution_findCommonAncestor.h"

Solution_findCommonAncestor::Solution_findCommonAncestor()
{
}

TreeNode* Solution_findCommonAncestor::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL)
		return root;
	if (root->val == p->val || root->val == q->val)
		return root;
	else
	{
		TreeNode* leftRet = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightRet = lowestCommonAncestor(root->right, p, q);
		if (leftRet && rightRet)
			return root;
		else
			return leftRet ? leftRet : rightRet;
	}
}

void Solution_findCommonAncestor::RunTest()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	TreeNode* p = root->left;
	TreeNode* q = root->right;
 	TreeNode* ret= lowestCommonAncestor(root, p, q);
	cout << ret->val << endl;
}
