#include "Solution_isPalindrome.h"

Solution_isPalindrome::Solution_isPalindrome()
{
}

bool Solution_isPalindrome::isPalindrome(ListNode* head)
{
	if (head == NULL)
		return true;

	ListNode* fast = head->next;
	ListNode* slow = head;
	while(fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* prev = NULL;
	ListNode* next = NULL;
	while(slow)
	{
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}
	slow = slow ? slow : prev;
	bool ret = true;
	while(head&&slow)
	{
		if (slow->val != head->val)
		{
			ret = false;
			break;
		}
		slow = slow->next;
		head = head->next;
	}
	return ret;
}

ListNode* Solution_isPalindrome::recursiveFunc(ListNode* head)
{
	if (head->next == NULL)
		return head;
	ListNode* tmp = recursiveFunc(head->next);
	if (left->val != tmp->val)
		flag = false;
	left = left->next;
	return head;
}

void Solution_isPalindrome::RunTest()
{
	RunTestCase({ 1 });
	RunTestCase({ 1,2 });
	RunTestCase({ 1,2 ,1});
	RunTestCase({ 1,2,3,4,1 });
	RunTestCase({ 1,2,3,2,1 });
	RunTestCase({ 1,2,1,2,1 });
}

void Solution_isPalindrome::RunTestCase(vector<int> list)
{
	ListNode* head = new ListNode(list);
	listPrinter->print(head);
	bool isPld = isPalindrome(head);
	if (isPld)
		cout << "是回文链表." << endl;
	else
		cout << "不是回文链表." << endl;
}
