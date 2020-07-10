#include "Solution_isPalindrome.h"

Solution_isPalindrome::Solution_isPalindrome()
{
}

bool Solution_isPalindrome::isPalindrome(ListNode* head)
{
	if (head == NULL)
		return false;

	flag = true;
	left = head;
	recursiveFunc(head);
	return flag;
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
