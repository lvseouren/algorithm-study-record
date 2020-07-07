#include "Solution_partition.h"

Solution_partition::Solution_partition()
{
}

ListNode* Solution_partition::partition(ListNode* head, int x)
{
	ListNode* dummy = head, *rightHead = NULL, *rightTail = NULL, *leftHead = NULL, *leftTail = NULL;
	while(dummy)
	{
		if(dummy->val>=x)
		{
			if (rightHead == NULL)
			{
				rightHead = dummy;
				rightTail = dummy;
			}
			else
			{
				rightTail->next = dummy;
				rightTail = dummy;
			}
		}
		if(dummy->val<x)
		{
			if(leftHead==NULL)
			{
				leftHead = dummy;
				leftTail = dummy;
			}else
			{
				leftTail->next = dummy;
				leftTail = dummy;
			}
		}
		dummy = dummy->next;
	}
	if (rightTail != NULL)
		rightTail->next = NULL;
	if (leftTail!=NULL)
	{
		leftTail->next = rightHead;
		return leftHead;
	}else
		return head;
}

void Solution_partition::RunTest()
{
	RunTestCase({ 1,4,3,2,5,2 }, 3);
	RunTestCase({ 1,4,3,2,5,2 }, 4);
	RunTestCase({ 1,4,3,2,5,2 }, 1);
	RunTestCase({ 1,4,3,2,5,2 }, 5);
	RunTestCase({ 1,4,3,2,5,2 }, 6);
	RunTestCase({ 1,4,3,2,5,2 }, 0);
}

void Solution_partition::RunTestCase(vector<int> list, int x)
{
	ListNode* root = new ListNode(list);
	cout << "分割数为:" << x << ",输入:" << endl;
	listPrinter->print(root);
	root = partition(root, x);
	cout << "输出:" << endl;
	listPrinter->print(root);
	cout << endl;
}
