#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_reverseList:SolutionBase
{
public:
	Solution_reverseList();
	ListNode* reverseList(ListNode* head);
	ListNode* reverseListRecursive(ListNode* head);
	void RunTest();
private:
	ListNode* reverseRecursive(ListNode*, ListNode*);
	void RunTestCase(vector<int> list);
};

