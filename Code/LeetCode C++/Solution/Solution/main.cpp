// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>

#include "contest.h"
#include "algorithm.h"
#include "solution.h"

void RunTest_Algorithm()
{
	algorithm al;
	al.RunTest();
}

void RunTest_Contest()
{
	contest ct;
	ct.RunTest();
}

void RunTest_Solution()
{
	solution s;
	s.RunTest();
}

int main()
{
	//------------------------------------------练习
	//RunTest_Solution();

	//------------------------------------------面试题
	//--bytedance
	//evenReorderMerge();

	//--------------------------------------------contest
	RunTest_Contest();

	//--------------------------------------------algorithm
	//RunTest_Algorithm();
}