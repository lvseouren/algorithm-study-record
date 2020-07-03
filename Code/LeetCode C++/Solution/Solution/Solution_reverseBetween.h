#pragma once
#include "TreeNode.h"

class Solution_reverseBetween
{
public:
	Solution_reverseBetween();
	ListNode* reverseBetween(ListNode* head, int m, int n);
	ListNode* reverseBetweenRecursive(ListNode* head, int m, int n);
	void RunTest();
private:
	ListNode* left;
	bool stop = false;
	void reverseAndRecurse(ListNode* head, int m, int n);
	void RunTestCase(vector<int> list, int m, int n);
};

