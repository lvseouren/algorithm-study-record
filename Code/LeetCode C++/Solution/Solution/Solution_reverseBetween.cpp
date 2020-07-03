#include "Solution_reverseBetween.h"
#include "ListPrinter.h"

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
	if (m == 1)
		return prev;
	else
		return ret;
}

void Solution_reverseBetween::RunTest()
{
	RunTestCase({ 5 }, 1, 1);
	RunTestCase({ 3,5 }, 1, 1);
	RunTestCase({ 3,5 }, 1, 2);
	RunTestCase({ 5,6,7,8,9 }, 1, 5);
	RunTestCase({ 5,6,7,8,9 }, 2, 5);
	RunTestCase({ 5,6,7,8,9 }, 2, 4);
}

void Solution_reverseBetween::RunTestCase(vector<int> list, int m, int n)
{
	ListPrinter* listPrinter = new ListPrinter();
	ListNode* testCase1 = new ListNode(list);
	listPrinter->print(testCase1);
	testCase1 = reverseBetween(testCase1, m, n);
	listPrinter->print(testCase1);
	cout << endl;
}
