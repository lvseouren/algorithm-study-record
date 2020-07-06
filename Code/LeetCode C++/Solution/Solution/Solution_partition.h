#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_partition:SolutionBase
{
public:
	Solution_partition();
	ListNode* partition(ListNode* head, int x);
	void RunTest();
	void RunTestCase(vector<int>, int);
};

