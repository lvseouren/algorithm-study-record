#pragma once
#pragma once
#include "SolutionBase.h"
#include <algorithm>
class Contest_au_2 :SolutionBase
{
public:
	int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) 
	{	
		sort(staple.begin(), staple.end());
		sort(drinks.begin(), drinks.end());
		int ret = 0;
		int drinkSize = drinks.size();
		for (int i = 0; i < staple.size(); ++i)
		{
			int left = 0;
			int right = drinkSize-1;
			while(left<=right)
			{
				int mid = left + (right - left) / 2;
				if (drinks[mid] + staple[i] > x)
				{
					right = mid-1;
				}
				else
				{
					left = mid+1;
				}
			}
			ret += (right +1);
			ret %= 1000000007;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ 10,20,5 }, { 5,5,2 }, 15);
		RunTestCase({ 2,1,1 }, { 8,9,5,1 }, 9);
		RunTestCase({  }, { 8,9,5,1 }, 9);
	}

	void RunTestCase(vector<int> staple, vector<int> drinks, int x)
	{
		int ret = breakfastNumber(staple, drinks, x);
		cout << "Output:"<<ret << endl << endl;
	}
};