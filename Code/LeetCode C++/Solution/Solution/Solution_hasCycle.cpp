#include "Solution_hasCycle.h"

Solution_hasCycle::Solution_hasCycle()
{
}

bool Solution_hasCycle::hasCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return false;
	ListNode* slow = head;
	ListNode* fast = head->next;
	bool hasCycle = false;
	while (fast && fast->next)
	{
		if (slow == fast)
		{
			hasCycle = true;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;
	}
	return hasCycle;
}

void Solution_hasCycle::RunTest()
{
	ListNode* head = new ListNode(1);
	ListNode* dummy = head;
	head->next = new ListNode(2);
	//head->next->next = head;
	bool cycle = hasCycle(head);
	if (cycle)
		cout << "有环" << endl;
	else
		cout << "无环" << endl;
}

void Solution_hasCycle::RunTestCase()
{
}
