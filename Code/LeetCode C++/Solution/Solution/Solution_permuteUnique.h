#pragma once
#include "SolutionBase.h"
class Solution_permuteUnique :SolutionBase {
	vector<vector<int>> result;
	vector<int> path;
	vector<int> visited;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		visited = vector<int>(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums);
		return result;
	}

	void backtrack(vector<int>& nums)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if(visited[i]==0)
			{
				if(i>0&&visited[i-1]==0&&nums[i]==nums[i-1])
				{

				}
				else
				{
					visited[i] = 1;
					int num = nums[i];
					path.push_back(num);
					backtrack(nums);
					path.pop_back();
					visited[i] = 0;
				}
			}
		}
	}

	void RunTest()
	{
		RunTestCase({ 1,1,2 });
		RunTestCase({ 1,2,3 });
	}

	void RunTestCase(vector<int> nums)
	{
		result.clear();
		path.clear();
		cout << "Input:" << endl;
		vecPrinter->print(nums);
		cout << "Output:" << endl;
		vecPrinter->print(permuteUnique(nums));
		cout << endl;
	}
};