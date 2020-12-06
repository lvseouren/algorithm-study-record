#pragma once
#include "SolutionBase.h"
class Solution_maxOperation :SolutionBase {
public:
	int maxOperations(vector<int>& nums, int k) 
	{
		int ret = 0;
		unordered_map<int, int> dict;
		for(int i = 0;i<nums.size();++i)
		{
			if(dict.find(nums[i])!=dict.end() && dict[nums[i]] > 0)
			{
				dict[nums[i]] -= 1;
				ret += 1;
			}else
			{
				int coNum = k - nums[i];
				AddOne(dict, coNum);
			}
		}
		return ret;
	}

	void AddOne(unordered_map<int,int>& map, int key)
	{
		if (map.find(key) != map.end())
			map[key]++;
		else
			map[key] = 1;
	}

	void RunTest()
	{
		RunTestCase({ 1,2,3,4 }, 5);
		RunTestCase({ 3,1,3,4,3 }, 6);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << "Input:" << endl;
		vecPrinter->print(nums);
		cout << "sum = " << k << endl;
		cout << "Output:"<< maxOperations(nums, k) << endl << endl;
	}
};