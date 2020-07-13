#pragma once
//2、给定一个链表，其中奇数位是升序的，偶数位是降序的，实现链表的排序
#include "SolutionBase.h"
class Solution_evenReorderMerge:SolutionBase
{
public:
	Solution_evenReorderMerge();
	ListNode* evenReorderMerge(ListNode*);
	void RunTest();
private:
	void RunTestCase(vector<int>);
};

