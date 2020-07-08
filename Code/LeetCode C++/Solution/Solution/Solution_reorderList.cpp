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
	//1.如果是链表只剩下1个元素或者空的话直接返回；
	if (!head || !head->next) return head;

	//2.找到当前链表的最后一个节点和倒数第二个节点
	//倒数第二个节点的next设置为null，然后剥离出来最后一个节点；
	ListNode* lastnode = head;
	ListNode* pre=NULL;
	while (lastnode->next) {
		pre = lastnode;
		lastnode = lastnode->next;
	}
	pre->next = nullptr;

	//3.将最后一个节点前插进来，然后他的next值就是递归的调用这个函数去处理
	ListNode* cur = head;
	ListNode* nextnode = cur->next;
	cur->next = lastnode;
	lastnode->next = recursiveFunc(nextnode);

	//4.直接返回头节点即可l
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
