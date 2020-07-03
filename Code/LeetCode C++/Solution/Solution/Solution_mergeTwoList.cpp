#include "Solution_mergeTwoList.h"
#include "ListPrinter.h"

Solution_mergeTwoList::Solution_mergeTwoList()
{
}

ListNode* Solution_mergeTwoList::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head = NULL;
	ListNode* dummy = NULL;
	while (l1 || l2)
	{
		if (l1 == NULL)
		{
			if (head == NULL)
			{
				head = l2;
				dummy = head;
			}
			else
			{
				dummy->next = l2;
				dummy = dummy->next;
			}
			l2 = l2->next;
		}
		else if (l2 == NULL)
		{
			if (head == NULL)
			{
				head = l1;
				dummy = head;
			}
			else
			{
				dummy->next = l1;
				dummy = dummy->next;
			}
			l1 = l1->next;
		}
		else
		{
			if (l1->val < l2->val)
			{
				if (head == NULL)
				{
					head = l1;
					dummy = head;
				}
				else
				{
					dummy->next = l1;
					dummy = dummy->next;
				}
				l1 = l1->next;
			}
			else
			{
				if (head == NULL)
				{
					head = l2;
					dummy = head;
				}
				else
				{
					dummy->next = l2;
					dummy = dummy->next;
				}
				l2 = l2->next;
			}
		}
	}
	return head;
}

void Solution_mergeTwoList::RunTest()
{
	RunTestCase({ 5 }, { 5 });
	RunTestCase({ 5 }, { 4 });
	RunTestCase({ 3,5 }, {1});
	RunTestCase({ 3,5 }, {3,5});
	RunTestCase({ 5,6,7,8,9 }, {1,2});
	RunTestCase({ 5,6,7,8,9 }, {1,10});
	RunTestCase({ 5,6,7,8,9 }, {5,10});
	RunTestCase({ 1,2,3 }, {1});
}

void Solution_mergeTwoList::RunTestCase(vector<int> list, vector<int> list2)
{
	ListPrinter* listPrinter = new ListPrinter();
	ListNode* l1 = new ListNode(list);
	ListNode* l2 = new ListNode(list2);
	listPrinter->print(l1);
	listPrinter->print(l2);
	l1 = mergeTwoLists(l1, l2);
	listPrinter->print(l1);
	cout << endl;
}
