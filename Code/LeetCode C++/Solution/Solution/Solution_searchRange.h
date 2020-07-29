#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int>& A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        
        while (left+1 < right)
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
};