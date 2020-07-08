#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_reorderList:SolutionBase
{
public:
	Solution_reorderList();
	void reorderList(ListNode* head);
	ListNode* reorderRecursive(ListNode* head);
	ListNode* recursiveFunc(ListNode* head);
	void RunTest();
private:
	void RunTestCase(vector<int>);
	ListNode* dummy;
	ListNode* next;
	ListNode* fast;
	ListNode* slow;
};

