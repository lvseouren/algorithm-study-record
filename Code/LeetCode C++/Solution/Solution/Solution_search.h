#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_search {
public:
	int search(vector<int>& nums, int target) 
	{
		if (nums.empty())
			return -1;
		return binarySearch(nums, 0, nums.size(), target);
	}

	int binarySearch(vector<int>& nums, int left, int right, int target)
	{
		if (left >= right - 1)
			return nums[left] == target ? left : -1;
		int mid = (left + right) / 2;
		int leftRet = binarySearch(nums, left, mid, target);
		if (leftRet >= 0)
			return leftRet;
		else
			return binarySearch(nums, mid, right, target);
	}

	void RunTest()
	{
		//RunTestCase({ -1,0,3,5,9,12 }, 9);
		//RunTestCase({ -1,0,3,5,9,12 }, 2);
		RunTestCase({ 2,5 }, 2);
	}

	void RunTestCase(vector<int> nums, int target)
	{
		cout << search(nums, target) << endl;
	}
};