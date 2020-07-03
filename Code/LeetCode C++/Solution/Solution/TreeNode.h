#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(vector<int> x)
	{
		ListNode* cur = NULL;
		vector<int>::iterator it = x.begin();
		val = *it;
		while (++it != x.end())
		{
			ListNode* nextNode = new ListNode(*it);
			if (cur)
				cur->next = nextNode;
			else
				next = nextNode;
			cur = nextNode;
		}
	}
};