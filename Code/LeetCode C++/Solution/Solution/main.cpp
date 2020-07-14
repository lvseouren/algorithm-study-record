﻿// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include "Solution_findRepeatNumber.h"
#include "Solution_subsets.h"
#include "Solution_maxDepth.h"
#include "Solution_validateBinarySearchTree.h"
#include "Solution_insertIntoBST.h"
#include "Solution_reverseList.h"
#include "Solution_reverseBetween.h"
#include "Solution_mergeTwoList.h"
#include "BSTPrinter.h"
#include "Solution_solveNQueens.h"
#include "Solution_findAllTreePath.h"
#include "Solution_maxPathSum.h"
#include "Solution_longestValidParentheses.h"
#include "Solution_findCommonAncestor.h"
#include "Solution_partition.h"
#include "Solution_sortList.h"
#include "Solution_reorderList.h"
#include "Solution_hasCycle.h"
#include "Solution_detectCycle.h"
#include "Solution_isPalindrome.h"
#include "Solution_evenReorderMerge.h"
#include "Solution_copyRandomList.h"
#include "MinStack.h"
#include "Solution_evalRPN.h"
#include "Solution_decodeString.h"

void PrintBST_preOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << ",";
	PrintBST_preOrder(root->left);
	PrintBST_preOrder(root->right);
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

void insertBST()
{
	Solution_insertIntoBST s;
	s.RunTest();
}

void reverseList()
{
	Solution_reverseList s;
	s.RunTest();
}

void reverserBetween()
{
	//ListNode* head = new ListNode({3,5});
	//PrintList(head);
	//Solution_reverseBetween s;
	//head = s.reverseBetween(head, 1, 2);
	//PrintList(head);
	Solution_reverseBetween s;
	s.RunTest();
}

void mergeTwoList()
{
	Solution_mergeTwoList s;
	s.RunTest();
}

void solveNQueens()
{
	Solution_solveNQueens s;
	s.RunTest();
}

void findAllTreePath()
{
	Solution_findAllTreePath s;
	s.RunTest();
}

void maxPathSum()
{
	Solution_maxPathSum s;
	s.RunTest();
}

void longestValidParentheses()
{
	Solution_longestValidParentheses s;
	s.RunTest();
}

void lowestCommonAncestor()
{
	Solution_findCommonAncestor s;
	s.RunTest();
}

void partition()
{
	Solution_partition s;
	s.RunTest();
}

void sortList()
{
	Solution_sortList s;
	s.RunTest();
}

void reorderList()
{
	Solution_reorderList s;
	s.RunTest();
}

void hasCycle()
{
	Solution_hasCycle s;
	s.RunTest();
}

void detectCycle()
{
	Solution_detectCycle s;
	s.RunTest();
}

void isPalindrome()
{
	Solution_isPalindrome s;
	s.RunTest();
}

void evenReorderMerge()
{
	Solution_evenReorderMerge s;
	s.RunTest();
}

void copyRandomList()
{
	Solution_copyRandomList s;
	s.RunTest();
}

void minStackTest()
{
	MinStack minStack;
	minStack.push(2);
	minStack.push(0);
	minStack.push(3);
	minStack.push(0);
	int min1 = minStack.getMin();  
	minStack.pop();
	int min2 = minStack.getMin();      
	minStack.pop();
	int min3 = minStack.getMin();
	minStack.pop();
	int min4 = minStack.getMin();
	cout << min1 << endl << min2 << endl << min3 << endl << min4 << endl;
}

void evalRPN()
{
	vector<string> input = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution_evalRPN s;
	cout << s.evalRPN(input) << endl;
}

void decodeString()
{
	Solution_decodeString s;
	string output = s.decodeString("3[a2[c]]");
}

int main()
{
	//findRepeatNumber();
	//subsets();
	//maxDepth();
	//isValidBST();
	//insertBST();
	//reverseList();
	//reverserBetween();
	//mergeTwoList();
	//solveNQueens();
	//findAllTreePath();
	//maxPathSum();
	//longestValidParentheses();
	//lowestCommonAncestor();
	//partition();
	//sortList();
	//reorderList();
	//hasCycle();
	//detectCycle();
	//isPalindrome();
	//copyRandomList();
	//minStackTest();
	//evalRPN();
	decodeString();

	//------------------------------------------面试题
	//--bytedance
	//evenReorderMerge();
}