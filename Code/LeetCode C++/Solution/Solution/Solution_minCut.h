#pragma once
#include "SolutionBase.h"
class Solution_minCut :SolutionBase {
public:
	int minCut(string s) 
	{
        int len = s.size();
        vector<int> dp(len, INT_MAX);
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));

        for(int right = 0;right<len;right++)
            for (int left = 0; left <= right; left++)
            {
                isPalindrome[left][right] = (s[left] == s[right]) && (right - left <= 1 || isPalindrome[left + 1][right - 1]);
            }

        for (int i = 0; i < len; i++)
        {
            if (isPalindrome[0][i])
            {
                dp[i] = 0;
                continue;
            }

            for (int j = 0; j < i; j++)
            {
                if (isPalindrome[j + 1][i])
                    dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[len - 1];
	}
	


    void RunTest()
    {
        RunTestCase("a");
        RunTestCase("ab");
        RunTestCase("aa");
        RunTestCase("aab");
        RunTestCase("aabaa");
        RunTestCase("abcba");
        RunTestCase("abcbd");
        RunTestCase("abcdb");
    }

    void RunTestCase(string s)
    {
        cout << "Input:" << s << endl;
        cout << "Output:" << minCut(s) << endl << endl;
    }
};