#pragma once
#include <vector>
#include "SolutionBase.h"
using namespace std;
class Solution_searchRange:SolutionBase {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int>& A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (A[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }

    //template3
	vector<int> searchRange_t3(vector<int>& nums, int target) 
    {
		// write your code here
        int cnt = nums.size();
        if (cnt == 0)
            return { -1,-1 };
        int left = 0, right = cnt - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid;
        }
        int retLeft = -1;
        if (nums[right] == target)
            retLeft = right;
        if (nums[left] == target)
            retLeft = left;

        left = max(retLeft,0), right = cnt - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (left<0||nums[mid] <= target)
                left = mid;
            else
                right = mid;
        }
        int retRight = -1;
        if (nums[left] == target)
            retRight = left;
		if (nums[right] == target)
            retRight = right;

        return { retLeft,retRight };
	}

	void RunTest()
	{
		RunTestCase({ 5,7,7,8,8,10 },6);
		RunTestCase({ 5,7,7,8,8,10 },8);
        RunTestCase({ 2,2 }, 2);
        RunTestCase({ 2,2 }, 1);
        RunTestCase({ 2 }, 1);
        RunTestCase({ 2 }, 2);
        RunTestCase({  }, 2);
	}

	void RunTestCase(vector<int> nums, int target)
	{
		cout <<"target:"<<target<< ",input:";
		vecPrinter->print(nums);
        cout << "output:" << endl;
        nums = searchRange_t3(nums, target);
        vecPrinter->print(nums);
        cout << endl;
	}
};