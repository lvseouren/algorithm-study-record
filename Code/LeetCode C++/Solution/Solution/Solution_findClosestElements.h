#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_findClosestElements:SolutionBase {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) 
	{
		int cnt = arr.size();
		if (cnt == 0)
			return arr;
		int left = 0, right = cnt - 1;
		vector<int> ret;
		int index = -1;
		while(left+1<right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == x)
			{
				index = mid;
				break;
			}
			else if (arr[mid] > x)
				right = mid;
			else
				left = mid;
		}
		if(index>0)
		{
			left = index - 1;
			right = index + 1;
		}
		else
		{
			index = getDiff(arr[left], x) > getDiff(arr[right], x) ? right++ : left--;
		}
		while (k > 0)
		{
			ret.push_back(arr[index]);
			k--;
			if(left>=0&&right<cnt)
			{
				index = getDiff(arr[left], x) > getDiff(arr[right], x) ? right++ : left--;
			}
			else if(left>=0)
			{
				index = left--;
			}else if(right<cnt)
			{
				index = right++;
			}
		}
		sort(ret.begin(),ret.end());
		return ret;
	}

	int getDiff(int x,int y)
	{
		return abs(x - y);
	}

	void RunTest()
	{
		RunTestCase({ 1,2,3,4,5 }, 4, 3);
		RunTestCase({ 1,2,3,4,5 }, 4, -1);
		RunTestCase({  }, 4, -1);
		RunTestCase({ 1 }, 1, -1);
		RunTestCase({ 1,2 }, 1, 1);
		RunTestCase({ 1,2 ,3}, 1, 1);
	}

	void RunTestCase(vector<int> nums, int k, int x)
	{
		cout << "k:" << k << ",x:" << x << ",input:";
		vecPrinter->print(nums);
		cout << "output:" << endl;
		nums = findClosestElements(nums, k, x);
		vecPrinter->print(nums);
		cout << endl;
	}
};