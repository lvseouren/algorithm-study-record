#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_findPeakElement:SolutionBase {
public:
	int findPeakElement(vector<int>& nums) 
	{

	}

	void RunTest()
	{
		RunTestCase({1,2,3,1});
		RunTestCase({ 1,2,1,3,5,6,4 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << findPeakElement(nums) << endl;
	}
};