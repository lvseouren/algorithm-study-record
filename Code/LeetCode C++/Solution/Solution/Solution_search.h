#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_search:SolutionBase {
public:
	int search(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size();
		while(left<right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			else if(nums[mid]<target)
			{
				left = mid+1;
			}
			else if (nums[mid] > target)
				right = mid;
		}
		return -1;
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

	/*���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

	(���磬����[0, 1, 2, 4, 5, 6, 7] ���ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2])��

	����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� - 1 ��

	����Լ��������в������ظ���Ԫ�ء�*/
	int searchInRotatedArray(vector<int>& nums, int target)
	{
		if (nums.empty())
			return -1;
		int left = 0, right = nums.size() - 1;
		if (target >= nums[0])
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] > target||nums[mid]<nums[0])
					right = mid - 1;
				else if (nums[mid] < target)
					left = mid + 1;
			}
		else
		{
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] < target||nums[mid]>=nums[0])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}

	void RunTest()
	{
		RunTestCase({ 3,1 }, 1);
		RunTestCase({ 5,1,3 }, 5);
		RunTestCase({ 3,4,5,6,1,2 }, 2);
	}

	void RunTestCase(vector<int> nums, int target)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "target:" << target << endl;
		cout << "output:" << searchInRotatedArray(nums, target) << endl;
	}
};