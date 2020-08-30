#pragma once
#include "SolutionBase.h"
class Solution_template :SolutionBase {
public:
	int funcname()
	{
		return 0;
	}

	void RunTest()
	{
		RunTestCase();
	}

	void RunTestCase()
	{
		cout << "Input:" << endl;
		cout << "Output:"<< funcname() << endl << endl;
	}
};