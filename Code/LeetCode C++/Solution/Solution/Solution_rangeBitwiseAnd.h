#pragma once
#include <iostream>
using namespace std;
class Solution_rangeBitwiseAnd {
public:
	int rangeBitwiseAnd(int m, int n) 
	{
		ListNode* before = new ListNode(-1);
		ListNode* dummy = before;
		int i = 0;
		for(i = 0;i<32;i++)
		{
			if (m & 1 << i)
			{
				dummy->next = new ListNode(i);
				dummy = dummy->next;
			}
		}

		ListNode* oneIndex = before->next;
		for(int i =m+1;i<n;++i)
		{
			if (oneIndex == NULL)
				break;
			//update ondIndex
			updateIndexList(oneIndex, i);
		}
		updateIndexList(oneIndex,n);
		int ret = 0;
		while (oneIndex)
		{
			ret |= 1 << oneIndex->val;
			oneIndex = oneIndex->next;
		}
		return ret;
	}

	void updateIndexList(ListNode*& head, int num)
	{
		ListNode* dummy = head, *prev = NULL;
		while(dummy)
		{
			if (num & 1 << dummy->val)
			{
				prev = dummy;
				dummy = dummy->next;
			}
			else
			{
				if (prev)
				{
					prev->next = dummy->next;
					prev = dummy;
					dummy = dummy->next;
				}else
				{
					head = dummy->next;
					dummy = dummy->next;
				}
			}
		}
	}

	void RunTest()
	{
		//RunTestCase(5, 7);
		RunTestCase(600000000, 2147483645);
		//RunTestCase(2147483646, 2147483647);
	}

	void RunTestCase(int m, int n)
	{
		cout << "m =" << m << ",n=" << n << endl;
		int output = rangeBitwiseAnd(m, n);
		cout << output << endl;
	}
};