#pragma once
#include "SolutionBase.h"
class Solution_helper :SolutionBase {
public:
	void printLongestConsecutive(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int retStart = 0, retStop = 0;
		int curStart = 0;
		int curLength = 0;
		for(int i = 1;i<nums.size();++i)
		{
			if(nums[i-1]==nums[i])
				continue;
			if(nums[i]==nums[i-1]+1)
			{
				curLength++;
			}else
			{
				if(curLength > retStop-retStart+1)
				{
					retStart = curStart;
					retStop = i-1;
				}
				curStart = i;
				curLength = 1;
			}
		}
		if(nums[nums.size()-1]-nums[curStart] + 1 == nums.size()-curStart)
		{
			retStart = curStart;
			retStop = nums.size()-1;
		}
		cout << "start=" << nums[retStart]<<endl;
		cout << "stop=" << nums[retStop]<<endl;
	}
};