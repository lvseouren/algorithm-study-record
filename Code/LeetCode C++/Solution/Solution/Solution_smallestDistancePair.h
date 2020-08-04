#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_smallestDistancePair:SolutionBase {
public:
	int smallestDistancePair(vector<int>& nums, int k) 
	{
		vector<int> distanceList;
		int n = nums.size();
		for(int i = 0;i<n;++i)
			for(int j = i+1;j<n;++j)
			{
				distanceList.push_back(abs(nums[i]-nums[j]));
			}

		sort(distanceList.begin(), distanceList.end());
		return distanceList[k-1];
	}

	void RunTest()
	{
		RunTestCase({ 1,3,1 }, 1);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << "input:";
		vecPrinter->print(nums);
		cout << "output:" << smallestDistancePair(nums, k) << endl;
		cout << endl;
	}
};