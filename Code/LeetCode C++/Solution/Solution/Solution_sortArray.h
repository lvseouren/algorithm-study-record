#pragma once
#include <iostream>
#include <vector>
#include "SolutionBase.h"
class Solution_sortArray:SolutionBase {
public:
	vector<int> tmp;
	vector<int> sortArray(vector<int>& nums) 
	{
		heapSort(nums);
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
		/*nums[right] = nums[i];
		nums[i] = pivot;*/
		swap(nums[i], nums[right]);

		quickSort(nums, left, i-1);
		quickSort(nums, i + 1, right);
	}

	void heapSort(vector<int>& nums)
	{
		PrintHeapInfo(nums, "初始堆:", true);
		int cnt = nums.size();
		for(int i = cnt/2-1;i>=0;i--)
			maxHeapify(nums, i, cnt-1);
		
		PrintHeapInfo(nums, "最大化堆处理结束:", true);
		for(int i =cnt-1;i>0;i--)
		{
			sink(nums, i);
		}
	}

	void maxHeapify(vector<int>& nums, int left, int right)
	{
		int dad = left;
		int son = dad * 2 + 1;
		while(son<= right)
		{
			if (son + 1 <= right && nums[son + 1] > nums[son])
				son++;
			if (nums[dad] > nums[son])
				return;
			else
			{
				swap(nums[dad], nums[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}

		PrintHeapInfo(nums, "maxHeapify:", true);
	}

	void sink(vector<int>& nums, int right)
	{
		swap(nums[0], nums[right]);
		PrintHeapInfo(nums, "sink:");
		maxHeapify(nums, 0, right - 1);
	}

	void swap(int& a,int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void PrintHeapInfo(vector<int>& nums, string msg, bool isNeedEndl=false)
	{
		cout << msg << endl;
		bstPrinter->print(bstPrinter->generateTree(&nums));
		if(isNeedEndl)
			cout << "-----------------------------------" << endl;
	}

	void RunTest()
	{
		RunTestCase({ 5,2,3,1 });
		RunTestCase({ 5,2,3 });
		RunTestCase({ 5,1,1,2,0,0 });
		RunTestCase({ 1 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		nums = sortArray(nums);
		cout << endl << "output:";
		vecPrinter->print(nums);
		cout << endl;
	}
};