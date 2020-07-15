#pragma once
#include "TreeNode.h"
#include <vector>
#include "SolutionBase.h"
class Solution_inorderTraversal:SolutionBase {
public:
	
	//µÝ¹é
	vector<int> inorderTraversal(TreeNode* root) 
	{
		if (root == NULL)
			return vector<int>();
		vector<int> left = inorderTraversal(root->left);
		vector<int> right = inorderTraversal(root->right);
		left.push_back(root->val);
		left.insert(left.end(), right.begin(),right.end());
		return left;
	}

	//µü´ú
	vector<int> inorderTraversal_iter(TreeNode* root)
	{
		if (root == NULL)
			return {};
		vector<int> ret;
		stack<TreeNode*> st;
		map<TreeNode*, bool> visited;
		st.push(root);
		while(!st.empty())
		{
			TreeNode* cur = st.top();
			if (cur->left && !visited[cur->left])
			{
				visited[cur->left] = true;
				st.push(cur->left);
			}
			else
			{
				st.pop();
				ret.push_back(cur->val);
				if (cur->right && !visited[cur->right])
				{
					visited[cur->right] = true;
					st.push(cur->right);
				}
			}	
		}
		return ret;
	}

	void RunTest()
	{
		TreeNode* head = new TreeNode(2);
		head->left = new TreeNode(1);
		head->right = new TreeNode(3);
		head->left->right = new TreeNode(4);
		vector<int> path = inorderTraversal_iter(head);
		vecPrinter->print(path);
	}
};