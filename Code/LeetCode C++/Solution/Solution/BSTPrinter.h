#pragma once
#include "TreeNode.h"
class BSTPrinter
{
public:
	BSTPrinter();
	void print(TreeNode* node);
	TreeNode* generateBST(vector<int>* list);
};

