#pragma once
//2������һ��������������λ������ģ�ż��λ�ǽ���ģ�ʵ�����������
#include "SolutionBase.h"
class Solution_evenReorderMerge:SolutionBase
{
public:
	Solution_evenReorderMerge();
	ListNode* evenReorderMerge(ListNode*);
	void RunTest();
private:
	void RunTestCase(vector<int>);
};

