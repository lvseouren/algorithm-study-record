#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution_splitArray {
public:
	int splitArray(vector<int>& nums, int m) 
	{
		int cnt = nums.size();
		int ret = INT_MIN;
		vector<long> sum;
		for (int i = 0; i < cnt; ++i)
		{
			if (i > 0)
				sum.push_back(sum[i-1] + nums[i]);
			else
				sum.push_back(nums[i]);
		}
		int average = sum[cnt-1] / m;
		int preCutIndex = -1;
		while(m>1)
		{
			int curIndex = preCutIndex + 1;
			int curSetSum;
			int left = curIndex, right = cnt - m;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				curSetSum = preCutIndex >= 0 ? sum[mid] - sum[preCutIndex] : sum[mid];
				if(curSetSum>average)
				{
					right = mid;
				}else
				{
					left = mid + 1;
				}
			}
			curSetSum = preCutIndex>=0?sum[right] - sum[preCutIndex]:sum[right];
			if (m>1&&right > 0&&right>preCutIndex+1)
			{
				int setSum = preCutIndex >= 0 ? sum[right-1] - sum[preCutIndex] : sum[right-1];
				if(abs(setSum-average)<abs(curSetSum-average))
				{
					right--;
					curSetSum = setSum;
				}
			}
			preCutIndex = right;
			ret = max(ret, curSetSum);
			m--;
		}
		if (preCutIndex >= 0)
			ret = max(ret, sum[cnt - 1] - sum[preCutIndex]);
		else
			ret = sum[cnt - 1];
		return ret;
	}

	void RunTest()
	{
		//RunTestCase({ 7,2,5,10,8 }, 2);
		//RunTestCase({ 1,3,1 }, 3);
		//RunTestCase({ 1,3,1 }, 2);
		//RunTestCase({ 1,3,1 }, 1);
		RunTestCase({ 10,5,13,4,8,4,5,11,14,9,16,10,20,8 }, 8);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << splitArray(nums, k) << endl;
	}
};