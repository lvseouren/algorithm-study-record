#include "Solution_findAllTreePath.h"

Solution_findAllTreePath::Solution_findAllTreePath()
{
    if(pathRet)
        pathRet->clear();
    else
        pathRet = new vector<vector<int>>();
    if (curPath)
        curPath->clear();
    else
        curPath = new vector<int>();
}

Solution_findAllTreePath::~Solution_findAllTreePath()
{
    delete(pathRet);
}

void Solution_findAllTreePath::findAllTreePath(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    bool noLeft = false;
    //添加选择
    curPath->push_back(root->val);
    //递归
    if (root->left)
        findAllTreePath(root->left);
    else
        noLeft = true;
    //回滚选择
    curPath->pop_back();

	//添加选择
	curPath->push_back(root->val);
	//递归
    if (root->right)
        findAllTreePath(root->right);
    else if (noLeft)
        pathRet->push_back(*curPath);

	//回滚选择
	curPath->pop_back();
}

void Solution_findAllTreePath::RunTest()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    findAllTreePath(root);
    vecPrinter->print(*pathRet);
}
