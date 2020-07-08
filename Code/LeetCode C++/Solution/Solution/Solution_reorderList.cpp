#include "Solution_reorderList.h"
#include "Solution_sortList.h"
#include "Solution_reverseList.h"
Solution_reorderList::Solution_reorderList()
{
}

ListNode* reverseListRecursive(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* ret = reverseListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return ret;
}

ListNode* findMiddleNode(ListNode* head)
{
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void Solution_reorderList::reorderList(ListNode* head)
{
	if (head == NULL)
		return;

	ListNode* middle = findMiddleNode(head);
	ListNode* rightHead = middle->next;
	rightHead = reverseListRecursive(rightHead);
	middle->next = NULL;

	ListNode* before = new ListNode(0);
	ListNode *dummy = before;
	bool isLeftTurn = true;
	while (head && rightHead)
	{
		if (isLeftTurn)
		{
			dummy->next = head;
			head = head->next;
		}
		else
		{
			dummy->next = rightHead;
			rightHead = rightHead->next;
		}
		isLeftTurn = !isLeftTurn;
		dummy = dummy->next;
	}
	if (head)
		dummy->next = head;
	if (rightHead)
		dummy->next = rightHead;

	head = before->next;
}

ListNode* Solution_reorderList::reorderRecursive(ListNode* head)
{
	dummy = head;
	slow = head;
	fast = head?head->next:NULL;
	recursiveFunc(head);
	return head;
}

ListNode* Solution_reorderList::recursiveFunc(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* ret = recursiveFunc(head->next);
	if (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	if (dummy == slow->next)
	{
		dummy->next = NULL;
		return NULL;
	}
	next = dummy->next;
	dummy->next = ret;
	dummy = next;
	ret->next = dummy;
	return head;
}

void Solution_reorderList::RunTest()
{
	RunTestCase({ });
	RunTestCase({ 1});
	RunTestCase({ 1,2,3,4 });
	RunTestCase({ 1,2,3,4,5 });
}

void Solution_reorderList::RunTestCase(vector<int> list)
{
	ListNode* root = NULL;
	if(list.size()>0)
		root = new ListNode(list);

	listPrinter->print(root);
	reorderRecursive(root);
	listPrinter->print(root);
	cout << endl;
}
