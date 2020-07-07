#pragma once
#include "SolutionBase.h"
class Solution_sortList:SolutionBase
{
public:
	Solution_sortList();
	ListNode* sortList(ListNode*);
	ListNode* mergeSort(ListNode* head);
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2);
	ListNode* findMiddleNode(ListNode* head);
	void RunTest();
private:
	void RunTestCase(vector<int>);
};

