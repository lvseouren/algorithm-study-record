#include "Solution_maxPathSum.h"

Solution_maxPathSum::Solution_maxPathSum()
{
	curMaxSum = 0;
}

void Solution_maxPathSum::RunTest()
{
	TreeNode* root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	int ret = maxPathSum(root);
	cout << ret << endl;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	ret = maxPathSum(root);
	cout << ret << endl;

	root = new TreeNode(2);
	root->left = new TreeNode(-1);
	root->right = new TreeNode(-2);
	ret = maxPathSum(root);
	cout << ret << endl;

	root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(11);
	root->right->left->left = new TreeNode(13);
	root->right->left->right = new TreeNode(4);
	root->right->left->left->left = new TreeNode(7);
	root->right->left->left->right = new TreeNode(2);
	root->right->left->left->left->right = new TreeNode(1);
	ret = maxPathSum(root);
	cout << ret << endl;
}

int Solution_maxPathSum::maxPathSum(TreeNode* root)
{
	curMaxSum = INT_MIN;
	calMaxPathSum(root);
	return curMaxSum;
}

int Solution_maxPathSum::calMaxPathSum(TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftPathSum = max(calMaxPathSum(root->left),0);
	int rightPathSum = max(calMaxPathSum(root->right),0);
	int maxPathNum = root->val + leftPathSum + rightPathSum;
	curMaxSum = max(curMaxSum, maxPathNum);

	return(root->val + max(leftPathSum, rightPathSum));
}
