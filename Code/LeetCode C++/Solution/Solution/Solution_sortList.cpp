#include "Solution_sortList.h"

Solution_sortList::Solution_sortList()
{
}

ListNode* Solution_sortList::sortList(ListNode* head)
{
	ListNode* dummy = head;
	ListNode* next = NULL;
	while(dummy)
	{
		next = dummy->next;
		dummy = next;
	}
}

void Solution_sortList::RunTest()
{
	RunTestCase({ 4,2,1,3 });
	RunTestCase({ -1,5,3,4,0 });
}

void Solution_sortList::RunTestCase(vector<int> vec)
{
	ListNode* head = new ListNode(vec);
	listPrinter->print(head);
	head = sortList(head);
	listPrinter->print(head);
	cout << endl;
}
