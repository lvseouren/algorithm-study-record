#pragma once
#include "SolutionBase.h"
class Contest_204_2:SolutionBase
{
public:
	//5500. 乘积为正数的最长子数组长度
	//	给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。
	//	一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。
	//	请你返回乘积为正数的最长子数组长度。
	int getMaxLen(vector<int>& nums) 
	{
		int cnt = nums.size();
		int maxLen = 0;
		int preZero = -1;
		int fushuCnt = 0;
		int a1=-1, a2=-1, a3=-1, a4=-1;
		for(int i = 0;i<=cnt;++i)
		{
			if(i==cnt||nums[i]==0)
			{
				if (fushuCnt % 2 == 0)
					maxLen = max(maxLen, i - preZero-1);
				else
				{
					int curMaxLen = 0;
					if(fushuCnt==1)
					{
						curMaxLen = max(a1 - preZero-1, i - a1-1);
					}else
					{
						curMaxLen = max(a4 - preZero-1, i - a1-1);
					}
					maxLen = max(curMaxLen, maxLen);
				}
				fushuCnt = 0;
				preZero = i;
				a1 = a2 = a3 = a4 = -1;
			}else if(nums[i]<0)
			{
				fushuCnt++;
				if (a1 >= 0 && a2 < 0)
					a2 = i;
				if (a1 < 0)
					a1 = i;
				a3 = a4;
				a4 = i;
			}
		}
		return maxLen;
	}

	void RunTest()
	{
		RunTestCase({ -16,0,-14,4,-13,-17,-19,-17,-21,-11,12 });
		RunTestCase({ 1, -2, -3, 4 });
		RunTestCase({ 0,1,-2,-3,-4 });
		RunTestCase({ -1,-2,-3,0,1 });
		RunTestCase({ -1,2 });
		RunTestCase({ 0,-1,-2,-3,-4 });
		RunTestCase({ -16,0,-5,2,2,-13,11,8 });
		RunTestCase({ 9,10,1,0,19,20,-28,30,-12,20,11,-8,7,21,-26 });
		RunTestCase({ 5, -20, -20, -39, -5, 0, 0, 0, 36, -32, 0, -7, -10, -7, 21, 20, -12, -34, 26, 2 });
		RunTestCase({ 0,0,0,0,0 });
		
	}

	void RunTestCase(vector<int> nums)
	{
		vecPrinter->print(nums);
		cout << "output:" << getMaxLen(nums) << endl << endl;
	}
};
