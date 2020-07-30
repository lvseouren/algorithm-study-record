#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_findPeakElement:SolutionBase {
public:
	int findPeakElement(vector<int>& nums) 
	{
		int numsCnt = nums.size();
		if (numsCnt == 0)
			return -1;
		else if (numsCnt == 1)
			return 0;
		int left = 0, right = numsCnt;
		while(left<right)
		{
			int mid = left + (right - left) / 2;
			if(mid>0&&mid< numsCnt-1)
			{
				if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
					left = mid + 1;
				else
					right = mid;
			}else
			{
				if (mid == 0)
				{
					if (nums[mid+1] < nums[mid])
						return mid;
					else
						left = mid + 1;
				}else
				{
					if (nums[mid] > nums[mid - 1])
						return mid;
					else
						right = mid;
				}
			}
		}
		if (left >= 0 && left < numsCnt)
		{
			int pre = left - 1;
			int next = left + 1;
			int preValue = pre >= 0 ? nums[pre] : INT_MIN;
			int nextValue = next < numsCnt ? nums[next] : INT_MIN;
			if((preValue<nums[left]&&nextValue<nums[left])||(preValue>nums[left]&&nextValue>nums[left]))
				return left;
		}
		return -1;
	}

	void RunTest()
	{
		RunTestCase({1,2,3,1});
		RunTestCase({ 1,2,1,3,5,6,4 });
		RunTestCase({ 1,2,1,3,5,6,7 });
		RunTestCase({ 3,2,6,6,5});
		RunTestCase({ 1 });
		RunTestCase({ 1,1 });
		RunTestCase({ 2,1,2 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << findPeakElement(nums) << endl;
	}
};