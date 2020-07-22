#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_singleNumer {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for (int num : nums)
            ret ^= num;
        return ret;
    }

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

    void RunTest()
    {
        //RunTestCase({ 2,2,1 });
        //RunTestCase({ 4,1,2,1,2 });

		RunTestCase({ 2,2,2,1 });
		RunTestCase({ 4,1,2,1,2,1,2 });
    }

    void RunTestCase(vector<int> nums)
    {
        cout << singleNumber_31(nums) << endl;
    }
};