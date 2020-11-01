#pragma once
#pragma once
#include "SolutionBase.h"
class Contest_213_1 :SolutionBase
{
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
	{
		int i = 0;
		int iMax = arr.size();
		int jMax = pieces.size();
		while(i<iMax)
		{
			bool fined = false;
			for(int j = 0;j<jMax;++j)
			{
				int kMax = pieces[j].size();
				if(pieces[j][0]==arr[i])
				{
					fined = true;
					i++;
					if (i == iMax)
						return kMax == 1;
					for (int k = 1; k < pieces[j].size(); ++k)
					{
						if (pieces[j][k] == arr[i])
						{
							i++;
							if (i == iMax)
								return kMax == k + 1 ;

						}
						else
						{
							if (k != 0)
								return false;
						}
					}
				}
			}
			if (!fined)
				return false;
		}
		return true;
	}

	void RunTest()
	{
		RunTestCase({ 15,88 }, { {88},{15} });
		RunTestCase({ 49, 18, 16 }, { {16, 18, 49} });
		RunTestCase({ 91,4,64,78 }, { {78},{4,64},{91} });
	}

	void RunTestCase(vector<int> arr, vector<vector<int>> pieces)
	{
		if (canFormArray(arr, pieces))
			cout << "true";
		else
			cout << "false";
		
		cout << endl;
		//cout << "Output:"<< smallestRange() << endl << endl;
	}
};