#pragma once
#include "SolutionBase.h"
class Solution_Answerofjudge :SolutionBase {
public:
	int Answerofjudge(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
		double middle = 0;
		int n = arr.size();
		if (n % 2 == 1)
			middle = arr[n / 2];
		else
			middle = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
		
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += arr[i];
		double average = sum*1.0 / n;
		if (middle > average)
			return 1;
		else if (middle < average)
			return -1;
		else
			return 0;
	}

	void RunTest()
	{
		RunTestCase({ 6,6,6,6,5,8 });
		RunTestCase({ 1 });
		RunTestCase({1,3,4});
		RunTestCase({ 7,4,8,11 });
	}

	void RunTestCase(vector<int> arr)
	{
		cout << "Output:"<< Answerofjudge(arr) << endl << endl;
	}
};