#pragma once
#include <vector>
#include <iostream>
#include "SolutionBase.h"
using namespace std;
class Solution_singleNumer:SolutionBase {
public:
    //����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ�������2�Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for (int num : nums)
            ret ^= num;
        return ret;
    }

    //����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
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

    //����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
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