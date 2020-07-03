#include "BSTPrinter.h"
#include "Solution_insertIntoBST.h"
BSTPrinter::BSTPrinter()
{
}

void BSTPrinter::print(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->val << ",";
	print(root->left);
	print(root->right);
}

TreeNode* BSTPrinter::generateBST(vector<int>* list)
{
	if (list == NULL || list->size() == 0)
		return NULL;
	vector<int>::iterator it = list->begin();
	TreeNode* root = new TreeNode(*it);
	Solution_insertIntoBST s;
	while (++it != list->end())
	{
		s.insertIntoBST(root, *it);
	}
	return root;
}
