#include "Solution_evenReorderMerge.h"

Solution_evenReorderMerge::Solution_evenReorderMerge()
{
}

ListNode* Solution_evenReorderMerge::evenReorderMerge(ListNode* head)
{
	if (head == NULL)
		return head;

	ListNode* dummy = head;
	ListNode* preEven = NULL;
	ListNode* curEven = NULL;
	while (dummy)
	{
		curEven = dummy->next;
		if (curEven)
		{
			dummy->next = curEven->next;
			curEven->next = preEven;
			dummy = dummy->next;
			preEven = curEven;
		}
		else
		{
			dummy = NULL;
		}
	}
	curEven = curEven ? curEven : preEven;
	ListNode* before = new ListNode(-1);
	dummy = before;
	while (head && curEven)
	{
		if (head->val < curEven->val)
		{
			dummy->next = head;
			head = head->next;
		}
		else
		{
			dummy->next = curEven;
			curEven = curEven->next;
		}
		dummy = dummy->next;
	}
	if (head)
		dummy->next = head;
	if (curEven)
		dummy->next = curEven;
	return before->next;
}

void Solution_evenReorderMerge::RunTest()
{
	RunTestCase({1,8,3,6,5,4,7,2});
	RunTestCase({ 1 });
	RunTestCase({ 1,8,3,6,5,4,7 });
	RunTestCase({ 1,9 });
	RunTestCase({ 9,1 });
}

void Solution_evenReorderMerge::RunTestCase(vector<int> list)
{
	ListNode* head = new ListNode(list);
	listPrinter->print(head);
	head = evenReorderMerge(head);
	listPrinter->print(head);
	cout << endl;
}
