#pragma once
#include "Contest_maxNumOfSubstrings.h"
#include "Contest_countSubTrees.h"
#include "Contest_204_1.h"
#include "Contest_204_2.h"
#include "Contest_204_3.h"
#include "Contest_204_4.h"

class contest
{
public:
	void RunTest()
	{
		RunTest_204();
	}

	void RunTest_198()
	{
		//Contest_maxNumOfSubstrings s;

		Contest_countSubTrees s;
		s.RunTest();
	}

	void RunTest_204()
	{
		//Contest_204_1 c1;
		//c1.RunTest();

		Contest_204_2 c2;
		c2.RunTest();

		//Contest_204_3 c3;
		//c3.RunTest();

		//Contest_204_4 c4;
		//c4.RunTest();
	}
};