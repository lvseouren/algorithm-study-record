#include "Solution_copyRandomList.h"
#include <map>
Solution_copyRandomList::Solution_copyRandomList()
{
}

RandomNode* Solution_copyRandomList::copyRandomList(RandomNode* head)
{
	if (head == NULL)
		return head;
	RandomNode* before = new RandomNode(-1);
	map<int, RandomNode*> intNewNodeDict;
	map<RandomNode*, int> oldNodeIntDict;
	int index = 0;
	RandomNode* dummy = before;
	while(head)
	{
		dummy->next = new RandomNode(head->val);
		dummy->next->index = head->index;//tobedelete
		dummy->next->random = head->random;
		intNewNodeDict[index] = dummy->next;
		oldNodeIntDict[head] = index;
		
		index++;
		dummy = dummy->next;
		head = head->next;
	}
	dummy = before->next;
	index = 0;
	while (dummy)
	{
		if (dummy->random)
			dummy->random = intNewNodeDict[oldNodeIntDict[dummy->random]];
		dummy = dummy->next;
	}
	return before->next;
}

void Solution_copyRandomList::RunTest()
{
	RandomNode* head = new RandomNode(7);
	head->index = 0;
	head->next = new RandomNode(13);
	head->next->index = 1;
	head->next->random = head;
	head->next->next = new RandomNode(11);
	head->next->next->index = 2;
	head->next->next->next = new RandomNode(10);
	head->next->next->next->random = head->next->next;
	head->next->next->next->index = 3;
	head->next->next->next->next = new RandomNode(1);
	head->next->next->next->next->random = head;
	head->next->next->next->next->index = 4;
	head->next->next->random = head->next->next->next->next;

	head = copyRandomList(head);
	while(head)
	{
		cout << "index = " << head->index;
		cout << ",val = " << head->val;
		if (head->random)
			cout << ",random = " << head->random->index;
		else
			cout << ",random = null";
		cout << endl;
		head = head->next;
	}
}
