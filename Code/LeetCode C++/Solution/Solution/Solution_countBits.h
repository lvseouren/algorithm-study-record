#pragma once
#include <vector>
#include <iostream>
#include "SolutionBase.h"
using namespace std;
class Solution_countBits:SolutionBase {
public:
	vector<int> countBits(int num) 
	{
		vector<int> ret(num+1, 0);
		int pre = 0;
		int curMax = INT_MIN;
		for (int i = 1; i <= num; i++)
		{
			ret[i] = ret[pre++] + 1;
			if (ret[i] > curMax)
			{
				curMax = ret[i];
				pre = 0;
			}
		}
		return ret;
	}

	int getCount(int num)
	{
		int ret = 0;
		while(num!=0)
		{
			num &= num - 1;
			ret++;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase(2);
		RunTestCase(5);
	}

	void RunTestCase(int n)
	{
		cout << "input:" << n << endl;
		cout << "output:";
		vector<int> output = countBits(n);
		vecPrinter->print(output);
	}
};