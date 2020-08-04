#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_findDuplicate:SolutionBase {
public:
	int findDuplicate(vector<int>& nums) 
	{
		int n = nums.size();
		int left = 0, right = n - 1, ret=-1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int fx = 0;
			for (int i = 0; i < n; i++)
				fx += (nums[i] <= mid);
			if(fx > mid)
			{
				right = mid - 1;
				ret = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 1,3,4,2,2 });
		RunTestCase({ 3,1,3,4,2 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << findDuplicate(nums) << endl;
		cout << endl;
	}
};