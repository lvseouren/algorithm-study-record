// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include "Solution_findRepeatNumber.h"
#include "Solution_subsets.h"
#include "Solution_maxDepth.h"

void findRepeatNumber();
void subsets();
void maxDepth();

int main()
{
	//findRepeatNumber();
	//subsets();
	maxDepth();
}

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
	int ret = s.maxDepth(&root);
	cout << "最大深度为：" << ret << endl;
}