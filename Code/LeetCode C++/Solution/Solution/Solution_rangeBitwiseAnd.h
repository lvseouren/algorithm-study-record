#pragma once
#include <iostream>
using namespace std;
class Solution_rangeBitwiseAnd {
public:
	//转化为m,n的最大公共前缀
	//使用反证法还是可以证明其正确性的
	int rangeBitwiseAnd(int m, int n) 
	{
		int cnt = 0;
		while(m!=n)
		{
			m >>= 1;
			n >>= 1;
			cnt++;
		}
		return m<<cnt;
	}

	void RunTest()
	{
		RunTestCase(5, 7);
		RunTestCase(600000000, 2147483645);
		RunTestCase(2147483646, 2147483647);
	}

	void RunTestCase(int m, int n)
	{
		cout << "m =" << m << ",n=" << n << endl;
		int output = rangeBitwiseAnd(m, n);
		cout << output << endl;
	}
};