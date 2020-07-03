#pragma once
#include "TreeNode.h"
class Solution_reverseList
{
public:
	Solution_reverseList();
	ListNode* reverseList(ListNode* head);
	ListNode* reverseListRecursive(ListNode* head);
private:
	ListNode* reverseRecursive(ListNode*, ListNode*);
};

