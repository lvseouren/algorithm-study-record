#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_reorderList:SolutionBase
{
public:
	Solution_reorderList();
	void reorderList(ListNode* head);
	void reorderRecursive(ListNode* head);
	void recursiveFunc(ListNode* head);
	void RunTest();
private:
	int t;
	int len;
	ListNode* left;
	ListNode* dummy;
	void RunTestCase(vector<int>);
};

