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
	if (head == NULL)
		return head;

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

void Solution_reorderList::reorderRecursive(ListNode* head)
{
	head = recursiveFunc(head);
}

ListNode* Solution_reorderList::recursiveFunc(ListNode* head)
{
	//1.���������ֻʣ��1��Ԫ�ػ��߿յĻ�ֱ�ӷ��أ�
	if (!head || !head->next) return head;

	//2.�ҵ���ǰ��������һ���ڵ�͵����ڶ����ڵ�
	//�����ڶ����ڵ��next����Ϊnull��Ȼ�����������һ���ڵ㣻
	ListNode* lastnode = head;
	ListNode* pre=NULL;
	while (lastnode->next) {
		pre = lastnode;
		lastnode = lastnode->next;
	}
	pre->next = nullptr;

	//3.�����һ���ڵ�ǰ�������Ȼ������nextֵ���ǵݹ�ĵ����������ȥ����
	ListNode* cur = head;
	ListNode* nextnode = cur->next;
	cur->next = lastnode;
	lastnode->next = recursiveFunc(nextnode);

	//4.ֱ�ӷ���ͷ�ڵ㼴��l
	return head;
}

void Solution_reorderList::RunTest()
{
	RunTestCase({ 1,2,3 });
	RunTestCase({1,2 });
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
