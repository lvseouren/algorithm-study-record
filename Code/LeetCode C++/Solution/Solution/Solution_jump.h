#pragma once
#include "SolutionBase.h"
class Solution_jump:SolutionBase {
public:
	int jump(vector<int>& nums) 
	{
		int cnt = nums.size();
		vector<int> dp(cnt, INT_MAX);
		dp[0] = 0;
		map<int, int> mapToLastIndex;
		mapToLastIndex[0] = 0;
		for (int i = 0; i < cnt; ++i)
		{
			dp[i] = getDp(i, mapToLastIndex);
			mapToLastIndex[dp[i] + 1] = mapToLastIndex.find(dp[i]+1)==mapToLastIndex.end()? i + nums[i]:max(mapToLastIndex[dp[i]+1],i+nums[i]);
		}
		return getDp(cnt-1,mapToLastIndex);
	}

	int getDp(int index, map<int,int>& data)
	{
		int ret = INT_MAX;
		for (auto value : data)
		{
			if (value.second >= index&&ret>value.first)
			{
				ret = value.first;
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 2,3,1,1,4 });
		RunTestCase({ 0 });
	}

	void RunTestCase(vector<int> nums)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << endl;
		cout<<"最小跳跃数是：" << jump(nums)<< endl << endl;
	}
};