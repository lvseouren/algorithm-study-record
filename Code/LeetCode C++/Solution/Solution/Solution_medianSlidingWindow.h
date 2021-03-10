#pragma once
#include "SolutionBase.h"
class Solution_medianSlidingWindow :SolutionBase {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) 
	{
		vector<double> ret;
		int left = 0;
		int right = left + k-1;
		while (right < nums.size())
		{
			double median;
			vector<int> window(nums.begin() + left, nums.begin() + right+1);
			sort(window.begin(), window.end());
			if (k % 2 == 0)
				median = window[k / 2 - 1] + (window[k / 2] - window[k / 2 - 1]) * 1.0 / 2;
			else
				median = window[k / 2];
			ret.push_back(median);
			left++;
			right++;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 1,3,-1,-3,5,3,6,7 }, 3);
		RunTestCase({ 1,3,-1,-3,5,3,6,7 }, 1);
	}

	void RunTestCase(vector<int> nums, int k)
	{
		cout << "Input:(k=" << k << ")" << endl;
		vecPrinter->print(nums);
		cout << "Output:" << endl;
		auto output = medianSlidingWindow(nums, k);
		vecPrinter->print(output);
	}
};