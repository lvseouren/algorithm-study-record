#pragma once
#include "TreeNode.h"

class Solution_reverseBetween
{
public:
	Solution_reverseBetween();
	ListNode* reverseBetween(ListNode* head, int m, int n);
	void RunTest();
private:
	void RunTestCase(vector<int> list, int m, int n);
};

