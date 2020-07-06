#include "Solution_partition.h"

Solution_partition::Solution_partition()
{
}

ListNode* Solution_partition::partition(ListNode* head, int x)
{
	ListNode* dummy = head, *rightHead = NULL, *leftTail = NULL,*prev = NULL,*next = NULL;
	while(dummy)
	{
		if(dummy->val>=x&&rightHead==NULL)
		{
			rightHead = dummy;
			leftTail = prev;
		}
		if(dummy->val<x)
		{
			if(rightHead)
			{
				prev->next = dummy->next;
				if (leftTail)
				{
					leftTail->next = dummy;
					leftTail = dummy;
				}
				else
					head = dummy;
				next = dummy->next;
				dummy->next = rightHead;
				dummy = next;
			}
		}
		prev = dummy;
		dummy = dummy!=NULL?dummy->next:dummy;
	}
	return head;
}

void Solution_partition::RunTest()
{
	RunTestCase({ 1,4,3,2,5,2 }, 3);
	RunTestCase({ 1,4,3,2,5,2 }, 4);
}

void Solution_partition::RunTestCase(vector<int> list, int x)
{
	ListNode* root = new ListNode(list);
	cout << "ÊäÈë:" << endl;
	listPrinter->print(root);
	root = partition(root, x);
	cout << "Êä³ö:" << endl;
	listPrinter->print(root);
}
