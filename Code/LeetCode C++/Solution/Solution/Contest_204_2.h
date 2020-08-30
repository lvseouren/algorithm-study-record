#pragma once
#include "SolutionBase.h"
class Contest_204_2:SolutionBase
{
public:
	int getMaxLen(vector<int>& nums) 
	{
		int cnt = nums.size();
		int maxLen = 0;
		return maxLen;
	}

	void RunTest()
	{
	/*	RunTestCase({ 1, -2, -3, 4 });
		RunTestCase({ 0,1,-2,-3,-4 });
		RunTestCase({ -1,-2,-3,0,1 });
		RunTestCase({ -1,2 });
		RunTestCase({ 1,2,3,5,-6,4,0,10 });
		RunTestCase({ 0,-1,-2,-3,-4 });
		RunTestCase({ -16,0,-5,2,2,-13,11,8 });
		RunTestCase({ 9,10,1,0,19,20,-28,30,-12,20,11,-8,7,21,-26 });*/
		RunTestCase({ 5, -20, -20, -39, -5, 0, 0, 0, 36, -32, 0, -7, -10, -7, 21, 20, -12, -34, 26, 2 });
		
	}

	void RunTestCase(vector<int> nums)
	{
		vecPrinter->print(nums);
		cout << "output:" << getMaxLen(nums) << endl << endl;
	}
};
