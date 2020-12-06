#pragma once
#include "SolutionBase.h"
#include <deque>
class Solution_concatenatedBinary :SolutionBase {
public:
	int concatenatedBinary(int n) 
	{
		int modular = 1e9 + 7;
		int ret= 0;
		int curExpo = 0;
		for(int i = n;i>0;--i)
		{
			deque<int> binarySt = dec2bin(i);
			while(!binarySt.empty())
			{
				int bitNum = binarySt.front();
				binarySt.pop_front();
				int factor = mypow(2, curExpo, modular);
				int addNum = (bitNum * factor) % modular;
				ret += addNum;
				ret %= modular;
				curExpo++;
			}
		}
		return ret;
	}

	int mypow(int a, int k, int base) {
		// 对因子求模
		a %= base;
		int res = 1;
		for (int _ = 0; _ < k; _++) {
			// 这里有乘法，是潜在的溢出点
			res *= a;
			// 对乘法结果求模
			res %= base;
		}
		return res;
	}

	deque<int> dec2bin(int num) 
	{
		deque<int> bin;
		while (num != 0) {
			bin.push_back(num % 2);
			num /= 2;
		}
		return bin;
	}

	void RunTest()
	{
		RunTestCase(1);
		RunTestCase(3);
		RunTestCase(100000);
	}

	void RunTestCase(int n)
	{
		cout << "Input:"<<n << endl;
		cout << "Output:"<< concatenatedBinary(n) << endl << endl;
	}
};