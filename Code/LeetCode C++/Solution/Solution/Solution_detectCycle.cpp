#include "Solution_detectCycle.h"
#include <map>
Solution_detectCycle::Solution_detectCycle()
{
}

ListNode* Solution_detectCycle::detectCycle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	bool hasCycle = false;

	while(fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			hasCycle = true;
			break;
		}
	}
	if (hasCycle)
	{
		fast = head;
		while (fast != slow)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
	else
		return NULL;
}

void Solution_detectCycle::RunTest()
{
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head->next;
	ListNode* startNode = detectCycle(head);
	if (startNode)
		cout << "有环，起点为：" << startNode->val << endl;
	else
		cout << "无环" << endl;
}
