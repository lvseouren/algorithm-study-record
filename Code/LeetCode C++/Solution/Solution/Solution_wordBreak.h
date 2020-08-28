#pragma once
#include "SolutionBase.h"
class Solution_wordBreak:SolutionBase {
public:
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		if (s.empty())
			return true;

		for (auto subStr : wordDict)
		{
			if (isStartWith(s, subStr))
			{

				bool ret = wordBreak(s.substr(subStr.size()), wordDict);
				if (ret)
					return true;
			}
		}
		return false;
	}

	bool isStartWith(string s, string subStr)
	{
		return s.substr(0, subStr.size()).compare(subStr) == 0;
	}

	void RunTest()
	{
		RunTestCase("leetcode", { "leet","code" });
		RunTestCase("catsandog", { "cats","dog","sand","and","cat" });
	}

	void RunTestCase(string s, vector<string> wordDict)
	{
		cout << "input:" << s << endl <<"Dict:";
		vecPrinter->print(wordDict);
		cout << (wordBreak(s, wordDict) ? "可以" : "不行") << endl << endl;
	}
};