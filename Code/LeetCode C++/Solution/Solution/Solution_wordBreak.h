#pragma once
#include "SolutionBase.h"
#include <set>
class Solution_wordBreak:SolutionBase {
public:
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		set<string> dict;
		int maxLen = 0;
		for (auto str : wordDict)
		{
			dict.insert(str);
			maxLen = max(maxLen, str.length());
		}
		int cnt = s.size();
		vector<bool> dp(cnt+1, false);
		dp[0] = true;
		for (int i = 1; i <= cnt; ++i)
		{
			for (int j = i; j >= 0 && j >= i - maxLen; --j)
			{
				if (dp[j] && dict.find(s.substr(j,i-j))!=dict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[cnt];
	}

	void RunTest()
	{
		RunTestCase("leetcode", { "leet","code" });
		RunTestCase("catsandog", { "cats","dog","sand","and","cat" });
		RunTestCase("catsandog", { "cats","dog","sand","and","cat", "an" });
	}

	void RunTestCase(string s, vector<string> wordDict)
	{
		cout << "input:" << s << endl <<"Dict:";
		vecPrinter->print(wordDict);
		cout << (wordBreak(s, wordDict) ? "可以" : "不行") << endl << endl;
	}
};