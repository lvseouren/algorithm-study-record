#include "Solution_sortList.h"
#include "Solution_mergeTwoList.h"

Solution_sortList::Solution_sortList()
{
}

ListNode* Solution_sortList::sortList(ListNode* head)
{
	head = mergeSort(head);
	return head;
}

ListNode* Solution_sortList::mergeSort(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* mid = findMiddleNode(head);
	ListNode* rightHead = mid->next;
	mid->next = NULL;
	ListNode* left = mergeSort(head);
	ListNode* right = mergeSort(rightHead);
	ListNode* result = mergeTwoList(left, right);
	return result;
}

ListNode* Solution_sortList::mergeTwoList(ListNode* l1, ListNode* l2)
{
	Solution_mergeTwoList s;
	return s.mergeTwoLists(l1, l2);
}

ListNode* Solution_sortList::findMiddleNode(ListNode* head)
{
	ListNode* fast = head->next;
	ListNode* slow = head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void Solution_sortList::RunTest()
{
	RunTestCase({ 4,2,1,3 });
	RunTestCase({ -1,5,3,4,0 });
	RunTestCase({ 0 });
}

void Solution_sortList::RunTestCase(vector<int> vec)
{
	ListNode* head = new ListNode(vec);
	listPrinter->print(head);
	head = sortList(head);
	listPrinter->print(head);
	cout << endl;
}
