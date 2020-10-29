#pragma once
#include "SolutionBase.h"
class Solution_sumNumbers :SolutionBase {
	int sum;
public:
	int sumNumbers(TreeNode* root)
	{
		sum = 0;
		func(0, root);
		return sum;
	}

	void func(int curNum, TreeNode* node)
	{
		if (node == NULL)
			return;
		else
		{
			curNum = curNum * 10 + node->val;
			if (node->left || node->right)
			{
				func(curNum, node->left);
				func(curNum, node->right);
			}
			else
			{
				sum += curNum;
			}
		}
	}

	void RunTest()
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
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