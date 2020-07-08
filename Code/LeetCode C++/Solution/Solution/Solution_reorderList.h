#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_reorderList:SolutionBase
{
public:
	Solution_reorderList();
	void reorderList(ListNode* head);
	void reorderRecursive(ListNode* head);
	ListNode* recursiveFunc(ListNode* head);
	void RunTest();
private:
	void RunTestCase(vector<int>);
};

