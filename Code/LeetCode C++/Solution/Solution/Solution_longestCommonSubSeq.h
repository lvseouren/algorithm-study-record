#pragma once
#include "SolutionBase.h"
class Solution_longestCommonSubSeq:SolutionBase {
public:
	int longestCommonSubsequence(string text1, string text2) 
	{
		if (text1.empty() || text2.empty())
			return 0;
		vector < vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
		for (int j = 0; j < text2.size(); ++j)
			for (int i = 0; i<text1.size(); ++i)
			{
				if (text2[j] == text1[i])
				{
					if (i > 0 && j > 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
					else
						dp[i][j] = 1;
				}
				else
				{
					int preI = i > 0 ? i - 1 : 0;
					int preJ = j > 0 ? j - 1 : 0;
					dp[i][j] = max(dp[i][j], dp[preI][preJ]);
					dp[i][j] = max(dp[i][j], dp[i][preJ]);
					dp[i][j] = max(dp[i][j], dp[preI][j]);			
				}
			}

		return dp[text1.size() - 1][text2.size() - 1];
	}

	void RunTest()
	{
		RunTestCase("abcde", "ace");
		RunTestCase("", "");
		RunTestCase("a", "");
		RunTestCase("aabaa", "aacbbaa");
		RunTestCase("bl", "yby");
		RunTestCase("psnw", "vozsh");
		RunTestCase("aaaa", "aaaaaaa");
	}

	void RunTestCase(string text1,string text2)
	{
		cout << "text1:" << text1 << endl << "text2:" << text2 << endl;
		cout << "longestCommonSubsequence:" << longestCommonSubsequence(text1, text2) << endl << endl;
	}
};