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
	return reverseRecursive(NULL, head);
}

ListNode* Solution_reverseList::reverseRecursive(ListNode* prev, ListNode* head)
{
	if (head == NULL)
		return prev;
	
	ListNode* next = head->next;
	head->next = prev;
	return reverseRecursive(head, next);
}