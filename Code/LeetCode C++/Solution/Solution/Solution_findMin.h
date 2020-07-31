#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_findMin:SolutionBase {
public:
    int findMin(vector<int>& nums) 
    {
		if (nums.empty())
			return -1;
		int cnt = nums.size();

		int left = 0, right = cnt;
		if (nums[0] > nums[cnt - 1])
		{
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] >= nums[0])
					left = mid + 1;
				else
					right = mid;
			}
			return nums[left];
		}
		else
			return nums[0];

    }

	void RunTest()
	{
		RunTestCase({ 3,4,5,1,2 });
		RunTestCase({ 4,5,6,7,0,1,2 });
		RunTestCase({ });
		RunTestCase({ 1 });
		RunTestCase({ 1,0 });
		RunTestCase({ 1,2 });
		RunTestCase({ 3,1,2 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << findMin(nums) << endl<<endl;
	}
};