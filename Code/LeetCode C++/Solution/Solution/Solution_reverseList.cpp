#include "Solution_reverseList.h"
Solution_reverseList::Solution_reverseList()
{
}

ListNode* Solution_reverseList::reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* next;
	while(head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

ListNode* Solution_reverseList::reverseListRecursive(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* ret = reverseListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return ret;
}

ListNode* Solution_reverseList::reverseRecursive(ListNode* prev, ListNode* head)
{
	if (head == NULL)
		return prev;
	
	ListNode* next = head->next;
	head->next = prev;
	return reverseRecursive(head, next);
}

void Solution_reverseList::RunTest()
{
	RunTestCase({ 10, 11, 12, 13, 14,15 });
}

void Solution_reverseList::RunTestCase(vector<int> list)
{
	ListNode* l = new ListNode(list); 
	listPrinter->print(l);
	l = reverseListRecursive(l);
	listPrinter->print(l);
	cout << endl;
}