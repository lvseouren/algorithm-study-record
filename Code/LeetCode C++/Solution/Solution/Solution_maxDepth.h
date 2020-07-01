#pragma once
 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution_maxDepth
{
public:
	Solution_maxDepth();
	int maxDepth(TreeNode* root);
};

