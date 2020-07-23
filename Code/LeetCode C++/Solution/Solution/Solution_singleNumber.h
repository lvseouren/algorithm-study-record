#pragma once
#include <vector>
#include <iostream>
#include "SolutionBase.h"
using namespace std;
class Solution_singleNumer:SolutionBase {
public:
    //给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了2次。找出那个只出现了一次的元素。
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for (int num : nums)
            ret ^= num;
        return ret;
    }

    //给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
    int singleNumber_31(vector<int>& nums)
    {
        int X = 0, Y = 0;
        for(int num:nums)
        {
            Y = ~X & (Y ^ num);
            X = ~Y & (X ^ num);
        }
        return Y;
    }

    //给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
    vector<int> singleNumber_212(vector<int>& nums)
    {
        int bitMask = 0;
        for (int num : nums)
            bitMask ^= num;
        int x = 0;
        int mask = bitMask&-bitMask;
        for (int num : nums)
        {
            if (num & mask)
                x ^= num;
        }
        return { x,x ^ bitMask };
	}

    void RunTest()
    {
        //RunTestCase({ 2,2,1 });
        //RunTestCase({ 4,1,2,1,2 });

	/*	RunTestCase({ 2,2,2,1 });
		RunTestCase({ 4,1,2,1,2,1,2 });*/
        RunTestCase({ 1,2,1,3,2,5 });
    }

    void RunTestCase(vector<int> nums)
    {
        vector<int> output = singleNumber_212(nums);
        vecPrinter->print(output);
    }
};