//76. 最小覆盖子串
//给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。
//这题跟732有异曲同工之妙
#pragma once
#include "SolutionBase.h"
class Solution_minWindow :SolutionBase {
public:
	string minWindow(string s, string t) 
	{
		int len = s.length();
		int left=0, right = 0;
		string ret = "";
		int minLen = INT_MAX;
		map<char, int> dict;
		map<char, int> windowDict;
		for (int i = 0; i < t.length(); ++i)
		{
			if (dict.find(t[i]) == dict.end())		
				dict[t[i]] = 1;			
			else			
				dict[t[i]]++;
		}

		int lackCount = dict.size();//当lackCount为0时，说明窗口内包含了t所有的元素
		bool isMoveRight = true;
		while (right < len)
		{
			if(isMoveRight)
				if (dict.find(s[right]) != dict.end())
				{
					if (windowDict.find(s[right]) != windowDict.end())
					{
						windowDict[s[right]]++;
					}
					else
					{
						windowDict[s[right]] = 1;
					}
					if (windowDict[s[right]] == dict[s[right]])
						lackCount--;
				}

			if (lackCount == 0)
			{
				if (minLen > right - left + 1)
					ret = s.substr(left, right-left+1);
				minLen = min(minLen, right - left + 1);

				if (dict.find(s[left]) != dict.end())
				{
					if (--windowDict[s[left]] < dict[s[left]])
						lackCount++;
				}
				left++;
				isMoveRight = false;
			}
			else
			{
				isMoveRight = true;
				right++;
			}
		}

		return ret;
	}

	void RunTest()
	{
		RunTestCase("ADOBECODEBANC","ABC");
		RunTestCase("babb", "baba");
		RunTestCase("aa", "aa");
		RunTestCase("aaba", "aaa");
	}

	void RunTestCase(string s, string t)
	{
		cout << "s=" <<s<<",t ="<<t<< endl;
		cout << "Output:"<< minWindow(s,t) << endl << endl;
	}
};