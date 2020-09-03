#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_smallestDistancePair:SolutionBase {
public:
	int smallestDistancePair(vector<int>& nums, int k) 
	{
		sort(nums.begin(), nums.end());
		int left = 0, right = nums[nums.size() - 1]-nums[0];
		while(left<right)
		{
			int mid = left + (right - left) / 2;
			int cnt = getPairCountLessThanDistance(nums, mid);
			if(cnt<k)
			{
				left = mid + 1;
			}else
			{
				right = mid;
			}
		}

		//懂了，其实return right更好理解，因为right最终必定会停在返回值，return left也对因为while的终止条件是left==right
		return left;//why?how to proof its correctness
	}

	int getPairCountLessThanDistance(vector<int>& nums, int distance)
	{
		int ret = 0;
		int start = 0;
		for(int i=0;i<nums.size();++i)
		{
			while (start < nums.size() && nums[i] - nums[start]>distance)++start;
			ret += i - start;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 1,3,1 }, 1);
		RunTestCase({ 1,3,5,7,9 }, 5);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << smallestDistancePair(nums, k) << endl;
		cout << endl;
	}
};