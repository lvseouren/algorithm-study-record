#pragma once
#include "SolutionBase.h"
class Solution_findAnagrams :SolutionBase {
public:
	vector<int> findAnagrams(string s, string p) 
	{
		int windowSize = p.size();
		int groupData[26] = {};

		for (int i = 0; i < windowSize; ++i)
		{
			groupData[p[i] - 'a']++;
		}

		int curMatchGroupCnt = 0;
		vector<int> ret;
		int left = 0, right = 0;
		while (right < s.size())
		{
			int rightId = s[right] - 'a';
			if (groupData[rightId] > 0)
				curMatchGroupCnt++;

			--groupData[rightId];
			right++;
			while (curMatchGroupCnt == windowSize)
			{
				if (right - left == windowSize)
					ret.push_back(left);
				int leftId = s[left] - 'a';
				if (groupData[leftId] == 0)
					curMatchGroupCnt--;
				groupData[leftId]++;
				left++;
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase("cbaebabacd", "abc");
		RunTestCase("abab","ab");
	}

	void RunTestCase(string s, string p)
	{
		cout << "Input: s = "<<s<<endl<<"p = "<<p << endl;
		vector<int> output = findAnagrams(s, p);
		vecPrinter->print(output);
		cout << endl;
	}
};