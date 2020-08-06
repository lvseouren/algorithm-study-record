#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution_splitArray {
public:
	int splitArray(vector<int>& nums, int m) 
	{
		long left = INT_MIN, right = 0;
		for(int i = 0;i<nums.size();++i)
		{
			left = max(left, nums[i]);
			right += nums[i];
		}
		while(left<right)
		{
			int mid = left + (right - left) / 2;
			if (check(nums, mid, m))
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}

	bool check(vector<int>& nums, int sum, int m)
	{
		int cnt = 1;
		int curSum = 0;
		for(int i = 0;i<nums.size();++i)
		{
			if (curSum + nums[i] > sum)
			{
				curSum = nums[i];
				cnt++;
			}else
			{
				curSum += nums[i];
			}
		}
		return cnt <= m;
	}

	void RunTest()
	{
		RunTestCase({ 7,2,5,10,8 }, 2);
		RunTestCase({ 1,3,1 }, 3);
		RunTestCase({ 1,3,1 }, 2);
		RunTestCase({ 1,3,1 }, 1);
		RunTestCase({ 10,5,13,4,8,4,5,11,14,9,16,10,20,8 }, 8);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << splitArray(nums, k) << endl;
	}
};