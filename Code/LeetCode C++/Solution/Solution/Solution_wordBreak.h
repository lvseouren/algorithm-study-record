#pragma once
#include "SolutionBase.h"
class Solution_wordBreak:SolutionBase {
public:
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		if (s.empty())
			return true;

		int cnt = s.size();
		vector<bool> dp(cnt, false);
		for (int i = 0; i < cnt; ++i)
		{
			for (auto subStr : wordDict)
			{
				if (dp[i])
					break;
				int len = subStr.size();
				if (i < len - 1)
					dp[i] = false;
				else
				{
					int pre = i - len;
					if (pre >= 0)
						dp[i] = pre+len<=cnt && s.substr(pre + 1, len).compare(subStr) == 0 && dp[pre];
					else
						dp[i] = pre + len <= cnt && s.substr(pre + 1, len).compare(subStr) == 0;
				}
			}
		}
		return dp[cnt-1];
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