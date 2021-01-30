#pragma once
#include "SolutionBase.h"

struct seq
{
	int first;
	int last;
};

class Solution_longestConsecutive :SolutionBase {
public:
	int longestConsecutive(vector<int>& nums) 
	{

	}

	void RunTest()
	{
		RunTestCase({ 100,4,200,1,3,2 });
		RunTestCase({ 99,100,98,101 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< longestConsecutive(nums) << endl << endl;
	}
};