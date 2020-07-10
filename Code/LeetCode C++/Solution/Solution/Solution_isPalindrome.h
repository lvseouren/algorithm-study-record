#pragma once
#include "TreeNode.h"
#include "SolutionBase.h"
class Solution_isPalindrome:SolutionBase
{
public:
	Solution_isPalindrome();
	bool isPalindrome(ListNode* head);
	ListNode* recursiveFunc(ListNode* head);
	void RunTest();
private:
	bool flag;
	ListNode* left;
	void RunTestCase(vector<int>);
};

