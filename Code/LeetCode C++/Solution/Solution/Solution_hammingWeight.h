#pragma once
#include <cstdint>
#include <iostream>
using namespace std;
class Solution_hammingWeight {
public:
	int hammingWeight(uint32_t n) 
	{
		int ret = 0;
		for(int i = 0;i<32;++i)
		{
			int x = 1 << i;
			if (n & 1 << i)
				ret++;
		}
		return ret;
	}

	int hammingWeight_2(uint32_t n)
	{
		int ret = 0;
		while(n!=0)
		{
			n &= n - 1;
			ret++;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase(uint32_t(1|1<<1|1<<3));
		RunTestCase(uint32_t(00000000000000000000000010000000));
		//RunTestCase(uint32_t(11111111111111111111111111111101));
	}

	void RunTestCase(uint32_t n)
	{
		cout << "input:" << n << endl;
		cout << "output:" << hammingWeight_2(n) << endl;
	}
};