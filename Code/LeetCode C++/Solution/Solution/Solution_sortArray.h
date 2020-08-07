#pragma once
#include <iostream>
#include <vector>
#include "SolutionBase.h"
class Solution_sortArray:SolutionBase {
public:
	vector<int> sortArray(vector<int>& nums) 
	{
		return mergeSort(nums, 0, nums.size()-1);
	}

	vector<int> mergeSort(vector<int>& nums, int left, int right)
	{
		if (left == right)
			return { nums[left] };
		int mid = (left + right) / 2;
		vector<int> leftNum = mergeSort(nums, left, mid);
		vector<int> rightNum = mergeSort(nums, mid+1, right);
		return merge(leftNum, rightNum);
	}

	vector<int> merge(vector<int> left, vector<int> right)
	{
		vector<int> ret;
		int i=0, j = 0;
		while(i<left.size()&&j<right.size())
		{
			ret.push_back(left[i] < right[j] ? left[i++] : right[j++]);
		}
		while(i<left.size())
		{
			ret.push_back(left[i++]);
		}
		while(j<right.size())
		{
			ret.push_back(right[j++]);
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 5,2,3,1 });
		RunTestCase({ 5,1,1,2,0,0 });
		RunTestCase({ 1 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << endl << "output:";
		nums = sortArray(nums);
		vecPrinter->print(nums);
		cout << endl;
	}
};