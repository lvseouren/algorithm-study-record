#pragma once
#include "SolutionBase.h"
class Solution_sortList:SolutionBase
{
public:
	Solution_sortList();
	ListNode* sortList(ListNode*);
	void RunTest();
private:
	void RunTestCase(vector<int>);
};

