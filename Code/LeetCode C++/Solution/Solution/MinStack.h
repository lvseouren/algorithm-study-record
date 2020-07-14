#pragma once
#include "TreeNode.h"
class MinStack {
public:
	/** initialize your data structure here. */
	ListNode* list;
	vector<int> data;
	int count = 0;

	MinStack() {
		count = 0;
	}

	void push(int x) {
		if (count > 0)
		{
			ListNode* dummy = list;
			ListNode* pre = NULL;
			ListNode* xNode = new ListNode(x);
			bool isPosFind = false;
			while(dummy)
			{
				if(dummy->val>x)
				{
					if(pre)
					{
						pre->next = xNode;
						xNode->next = dummy;
					}
					else
					{
						xNode->next = dummy;
						list = xNode;
					}
					isPosFind = true;
					break;
				}
				pre = dummy;
				dummy = dummy->next;
			}
			if(!isPosFind)
			{
				pre->next = xNode;
			}
		}
		else
		{
			list = new ListNode(x);
		}
		data.push_back(x);
		count++;
	}

	void pop() {
		int x = data[count-1];
		count--;
		data.pop_back();
		ListNode* dummy = list, *pre = NULL;
		while(dummy)
		{
			if(dummy->val == x)
			{
				if(pre)
				{
					pre->next = dummy->next;
					delete dummy;
				}else
				{
					list = dummy->next;
					delete dummy;
				}
				dummy = NULL;
				break;
			}
			pre = dummy;
			dummy = dummy->next;
		}
	}

	int top() {
		return data[count - 1];
	}

	int getMin() {
		return list->val;
	}
};