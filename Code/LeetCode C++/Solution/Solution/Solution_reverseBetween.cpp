#include "Solution_reverseBetween.h"
#include "ListPrinter.h"

Solution_reverseBetween::Solution_reverseBetween(){}

ListNode* Solution_reverseBetween::reverseBetween(ListNode* head, int m, int n)
{
	if (head == NULL)
		return head;
	int i = 0;
	ListNode* left = NULL;//左断点,当m==1时，为NULL
	ListNode* nodeM = NULL;
	ListNode* prev = NULL;
	ListNode* next = NULL;
	ListNode* dummy = head;
	while(i<m)
	{
		prev = dummy;
		dummy = dummy->next;
		i++;
		if (i == m - 1)
			left = prev;
	}
	nodeM = prev;
	while(i<n&&dummy)
	{
		next = dummy->next;
		dummy->next = prev;
		prev = dummy;
		dummy = next;
		i++;
	}
	
	nodeM->next = dummy;
	if (left)
	{
		left->next = prev;
	}
	else
		head = prev;

	return head;
}

ListNode* Solution_reverseBetween::reverseBetweenRecursive(ListNode* head, int m, int n)
{
	stop = false;
	left = head;
	reverseAndRecurse(head, m, n);
	return head;
}

void Solution_reverseBetween::reverseAndRecurse(ListNode* right, int m, int n)
{
	if (n == 1)
		return;
	right = right->next;
	if (m > 1)
		left = left->next;
	reverseAndRecurse(right, m - 1, n - 1);
	if (left == right || right->next == left)
		stop = true;

	if(!stop)
	{
		int temp = left->val;
		left->val = right->val;
		right->val = temp;
		left = left->next;
	}
}

void Solution_reverseBetween::RunTest()
{
	RunTestCase({ 5 }, 1, 1);
	RunTestCase({ 3,5 }, 1, 1);
	RunTestCase({ 3,5 }, 1, 2);
	RunTestCase({ 5,6,7,8,9 }, 1, 5);
	RunTestCase({ 5,6,7,8,9 }, 2, 5);
	RunTestCase({ 5,6,7,8,9 }, 2, 4);
	RunTestCase({ 1,2,3 }, 1, 2);
}

void Solution_reverseBetween::RunTestCase(vector<int> list, int m, int n)
{
	cout << "m=" << m << ",n=" << n<<","<<endl;
	ListPrinter* listPrinter = new ListPrinter();
	ListNode* testCase1 = new ListNode(list);
	listPrinter->print(testCase1);
	//testCase1 = reverseBetween(testCase1, m, n);
	testCase1 = reverseBetweenRecursive(testCase1, m, n);
	listPrinter->print(testCase1);
	cout << endl;
}
