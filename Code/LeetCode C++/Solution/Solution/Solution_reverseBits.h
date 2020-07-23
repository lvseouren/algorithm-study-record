#pragma once
#include <cstdint>

class Solution_reverseBits {
public:
	uint32_t reverseBits(uint32_t n) 
	{
		uint32_t ret = 0;
		for(int i = 0;i<32;i++)
		{
			uint32_t ni = n & (1 << i);
			if(ni)
				ret |= (1<<(31-i));
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase(2);
	}

	void RunTestCase(uint32_t n)
	{
		n = reverseBits(n);
		cout << n;
	}
};