#pragma once
#include "SolutionBase.h"
class Solution_validMountainArray :SolutionBase {
public:
	bool validMountainArray(vector<int>& A) 
	{
		int len = A.size();
		if (len < 3)
			return false;

		if (A[1] <= A[0])
			return false;
		bool isUping = true;
		for(int i = 1;i<len;++i)
		{
			if(isUping)
			{
				if (A[i] < A[i - 1])
					isUping = false;
				else if (A[i] == A[i - 1])
					return false;
			}
			else
			{
				if (A[i - 1] < A[i])
					return false;
				else if (A[i - 1] == A[i])
					return false;
			}
		}
		return not isUping;
	}

	void RunTest()
	{
		RunTestCase({ 0,1,2,3,4,5,6,7,8,9 });
		RunTestCase({ 1,0,1 });
		RunTestCase({ 1,1,1 });
		RunTestCase({ 1,2,1 });
		RunTestCase({ 1,2,1,1 });
		RunTestCase({2,1});
		RunTestCase({ 3,5,5 });
		RunTestCase({ 0,3,2,1 });
	}

	void RunTestCase(vector<int> A)
	{
		cout << "Input:" << endl;
		vecPrinter->print(A);
		if (validMountainArray(A))
			cout << "true" << endl;
		else
			cout << "false" << endl;
		cout << endl;
	}
};