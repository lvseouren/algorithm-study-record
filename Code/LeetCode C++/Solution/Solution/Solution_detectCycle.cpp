#include "Solution_detectCycle.h"
#include <map>
Solution_detectCycle::Solution_detectCycle()
{
}

ListNode* Solution_detectCycle::detectCycle(ListNode* head)
{
	ListNode* dummy = head;
	ListNode* startNode = NULL;
	map<ListNode*, bool> nodeDict;
	while(dummy)
	{
		if (nodeDict.count(dummy))
		{
			startNode = dummy;
			break;
		}
		nodeDict[dummy] = true;
		dummy = dummy->next;
	}
	return startNode;
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
