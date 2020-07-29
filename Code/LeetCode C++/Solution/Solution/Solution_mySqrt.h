#pragma once
#include <cmath>
class Solution_mySqrt {
public:
	int mySqrt(int x) 
	{
		int left = 0, right = x;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			double curPow = pow(mid,2);
			if (curPow == x)
				return mid;
			else if (curPow > x)
				right = mid - 1;
			else if (curPow < x)
				left = mid + 1;
		}
		return right;
	}


	void RunTest()
	{
		RunTestCase(2147395599);

	}

	void RunTestCase(int input)
	{
		cout << "input:" << input << endl;
		cout << "output:" << mySqrt(input) << endl;
	}
};