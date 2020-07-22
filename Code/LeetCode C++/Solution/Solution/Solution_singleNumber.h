#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_singleNumer {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for (auto num : nums)
            ret ^= num;
        return ret;
    }

    void RunTest()
    {
        RunTestCase({ 2,2,1 });
        RunTestCase({ 4,1,2,1,2 });
    }

    void RunTestCase(vector<int> nums)
    {
        cout << singleNumber(nums) << endl;
    }
};