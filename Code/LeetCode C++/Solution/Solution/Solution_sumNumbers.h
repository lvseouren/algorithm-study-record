#pragma once
#include "SolutionBase.h"
class Solution_sumNumbers :SolutionBase {
public:
	int sumNumbers(TreeNode* root)
	{
		return func(0, root);
	}

	int func(int curNum, TreeNode* node)
	{
		if (node == NULL)
			return 0;
		else
		{
			curNum = curNum * 10 + node->val;
			if (node->left || node->right)
			{
				return func(curNum, node->left) + func(curNum, node->right);
			}
			else
			{
				return curNum;
			}
		}
	}

	void RunTest()
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(1);
		RunTestCase(root);
		root = new TreeNode(4);
		root->left = new TreeNode(9);
		root->right = new TreeNode(0);
		root->left->left = new TreeNode(5);
		root->left->right = new TreeNode(1);
		RunTestCase(root);
	}

	void RunTestCase(TreeNode* root)
	{
		cout << "Input:" << endl;
		bstPrinter->printBFS(root);
		cout << "Output:"<< sumNumbers(root) << endl << endl;
	}
};