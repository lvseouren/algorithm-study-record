#include "Solution_reverseList.h"
Solution_reverseList::Solution_reverseList()
{
}

ListNode* Solution_reverseList::reverseList(ListNode* head)
{
	ListNode* ret = head;
	ListNode* prev = NULL;
	ListNode* next;
	while(head)
	{
		next = head->next;
		if(prev!=NULL)
			head->next = prev;
		prev = head;
		head = head->next;
		ret = prev;
	}
	return ret;
}