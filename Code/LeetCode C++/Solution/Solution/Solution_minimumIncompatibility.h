#pragma once
#include "SolutionBase.h"
class Solution_minimumIncompatibility :SolutionBase {
public:
	int minimumIncompatibility(vector<int>& nums, int k) 
	{
		int cnt = nums.size();
		if (cnt % k != 0)
			return -1;
		int subArraySize = cnt / k;

		vector<int> visited(cnt, 0);
		sort(nums.begin(), nums.end());
		int curIndex = 0;
		int nextStartIndex = INT_MAX;
		int curSubArraySize = 0;
		int curSubArrayCnt = 0;

		int curArrayMin = INT_MAX;
		int curArrayMax = INT_MIN;
		
		int preArrayNum = 0;
		int ret = 0;
		while(curIndex < cnt)
		{
			if (visited[curIndex] > 0)
			{
				curIndex++;
				continue;
			}
			if(curSubArraySize == 0 || nums[curIndex] != preArrayNum )
			{
				preArrayNum = nums[curIndex];
				visited[curIndex] = 1;
				curArrayMin = min(curArrayMin, nums[curIndex]);
				curArrayMax = max(curArrayMax, nums[curIndex]);
				curSubArraySize++;
			}else
			{
				nextStartIndex = min(nextStartIndex, curIndex);
			}
			if(curSubArraySize==subArraySize)
			{
				curSubArraySize = 0;
				curSubArrayCnt++;
				curIndex = nextStartIndex;
				ret += (curArrayMax - curArrayMin);
				curArrayMin = INT_MAX;
				curArrayMax = INT_MIN;
			}else
				curIndex++;
		}
		if (curSubArrayCnt == k)
			return ret;
		else
			return -1;
	}

	void RunTest()
	{
		RunTestCase({ 1,2,1,4 }, 2);
		RunTestCase({ 6,3,8,1,3,1,2,2 }, 4);
		RunTestCase({ 5,3,3,6,3,3 }, 3);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< minimumIncompatibility(nums, k) << endl << endl;
	}
};
