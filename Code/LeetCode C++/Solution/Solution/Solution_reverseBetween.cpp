#include "Solution_reverseBetween.h"

Solution_reverseBetween::Solution_reverseBetween(){}

ListNode* Solution_reverseBetween::reverseBetween(ListNode* head, int m, int n)
{
	if (m == n)
		return head;
	ListNode* ret = head;
	int i = 1;
	ListNode* left = NULL;
	while (i < m && head != NULL)
	{
		i++;
		if (i == m)
			left = head;
		head = head->next;
	}

	if (head == NULL)
		return head;

	ListNode* next;
	ListNode* prev = NULL;
	while(i++<=n&&head!=NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	if(left!=NULL)
	{
		left->next->next = head;
		left->next = prev;
	}
	return ret;
}