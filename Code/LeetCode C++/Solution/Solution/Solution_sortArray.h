#pragma once
#include <iostream>
#include <vector>
#include "SolutionBase.h"
class Solution_sortArray:SolutionBase {
public:
	vector<int> tmp;
	vector<int> sortArray(vector<int>& nums) 
	{
		quickSort(nums, 0, nums.size()-1);
		return nums;
	}

	void mergeSort(vector<int>& nums, int left, int right)
	{
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid+1, right);
		merge(nums, left, mid, right);
	}

	void merge(vector<int>& nums, int left, int mid, int right)
	{
		int i = left, j = mid+1;
		int index = left;
		while (i <= mid && j <= right)
		{
			tmp[index++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
		}
		while(i<=mid)
		{
			tmp[index++] = nums[i++];
		}
		while(j<=right)
		{
			tmp[index++] = nums[j++];
		}
		for(int i = 0;i<right-left+1;i++)
		{
			nums[left + i] = tmp[left+i];
		}
	}

	void quickSort(vector<int>& nums, int left, int right)
	{
		if (left >= right||left<0||right>=nums.size())
			return;
		int i = left, j = right, pivot = nums[right];
		while(i!=j)
		{
			while (i < j && nums[i] <= pivot)
				i++;
			while (i < j && nums[j] >= pivot)
				j--;
			
			if (i < j)
				swap(nums[i], nums[j]);
		}
		nums[right] = nums[i];
		nums[i] = pivot;
		
		quickSort(nums, left, i-1);
		quickSort(nums, i + 1, right);
	}

	void swap(int& a,int& b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	void RunTest()
	{
		//RunTestCase({ 5,2,3,1 });
		RunTestCase({ 5,1,1,2,0,0 });
		//RunTestCase({ 1 });
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