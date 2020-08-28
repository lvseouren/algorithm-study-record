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
	
    string longestPalindrome(string inputS)
    {
        int pos = 0;
        int maxLen = 0;

        string s = addBoundaries(inputS,'#');
        int cnt = s.size();
        int R=0,center=0;
        vector<int> dp(cnt, 0);
        for (int i = 0; i < cnt; i++)
        {
            if (i < R)
            {  
                int mirror = 2 * center - i;
            /*    if (dp[mirror] <= R - i)
                    dp[i] = dp[mirror];
                else
                    dp[i] = R - i;*/
                dp[i] = min(dp[mirror], R - i);
            }
			int left = i - (1+dp[i]);
			int right = i + (1+dp[i]);
			while (left >= 0 && right < cnt && s[left] == s[right])
			{
				left--;
				right++;
				dp[i]++;
			}
			if (dp[i] > maxLen)
			{
                maxLen = dp[i];
                pos = (i - maxLen)/2;
			}
			if (i+dp[i] > R)
			{
				R = i+dp[i];
				center = i;
			}
        }

        return inputS.substr(pos, maxLen);
    }

	string addBoundaries(string s, char divide)
	{
        int cnt = s.size();
        if (cnt == 0)
            return s;
        string ret = string(cnt * 2 + 1, divide);
        for (int i = 0; i < cnt; ++i)
        {
            ret[i << 1 | 1] = s[i];
        }
        return ret;
	}

    void RunTest()
	{
		RunTestCase("");
        RunTestCase("a");
        RunTestCase("ab");
        RunTestCase("aa");
        RunTestCase("aab");
        RunTestCase("aabaa");
        RunTestCase("abcba");
        RunTestCase("abcbd");
        RunTestCase("abcdb");
        RunTestCase("abccbb");
    }

    void RunTestCase(string s)
    {
        cout << "Input:" << s << endl;
        //cout << "Output:" << minCut(s) << endl << endl;
        cout << "Output:" << longestPalindrome(s) << endl << endl;
    }
};