// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include "Solution_findRepeatNumber.h"
#include "Solution_subsets.h"
#include "Solution_maxDepth.h"
#include "Solution_validateBinarySearchTree.h"

void findRepeatNumber();
void subsets();
void maxDepth();

void findRepeatNumber()
{
	std::vector<int> nums = { 3,1,2,3 };
	std::map<int, bool> table;
	Solution_findRepeatNumber s;
	s.findRepeatNumber(nums);
}

void subsets()
{
	vector<int> nums = { 1,2,3 };
	Solution_subsets s;
	s.subsets(nums);
	//s.subsets_backtrack(nums);
}

void maxDepth()
{
	Solution_maxDepth s;
	TreeNode root(3);
	root.left = new TreeNode(9);
	root.right = new TreeNode(20);
	root.right->left = new TreeNode(15);
	root.right->right = new TreeNode(7);
	int ret = s.maxDepth_iterate_bfs(&root);
	cout << "最大深度为：" << ret << endl;
}

void isValidBST()
{
	TreeNode root(4);
	root.left = new TreeNode(3);
	root.right = new TreeNode(15);
	root.right->left = new TreeNode(9);
	root.right->right = new TreeNode(20);
	Solution_validateBinarySearchTree s;
	bool ret = s.isValidBST(&root);
	if (ret)
		cout << "是有效的二叉查找树" << endl;
	else
		cout << "不是有效的二叉查找树" << endl;
}

int main()
{
	//findRepeatNumber();
	//subsets();
	//maxDepth();
	isValidBST();
}