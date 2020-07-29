#pragma once
#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution_firstBadVersion {
public:
	int ver;
	int firstBadVersion(int n) 
	{
		int left = 0, right = n;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
		}

		if (left <= n && isBadVersion(left))
			return left;
		return -1;
	}

	void RunTest()
	{
		RunTestCase(5, 4);
	}

	bool isBadVersion(int input)
	{
		return input >= ver;
	}

	void RunTestCase(int n, int version)
	{
		ver = version;
		cout << "input:"<<n<<",badVersion:"<<version<<endl;
		cout << "output:" << firstBadVersion(n) << endl;
	}
};