#pragma once
#include "TreeNode.h"
class Solution_mergeTwoList
{
public:
	Solution_mergeTwoList();
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	void RunTest();
private:
	void RunTestCase(vector<int> list, vector<int> list2);
};

