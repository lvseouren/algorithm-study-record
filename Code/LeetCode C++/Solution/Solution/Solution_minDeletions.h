#pragma once
#include "SolutionBase.h"
#include <algorithm>
class Solution_minDeletions :SolutionBase {
public:
	int minDeletions(string s) 
	{
		vector<int> cnt(26, 0);
		for(int i= 0;i<s.size();++i)
		{
			int id = s[i] - 'a';
			cnt[id]++;
		}

		sort(cnt.begin(), cnt.end(), greater<int>());
		int ret = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (cnt[i] == 0)
				break;
			for (int j = i + 1; j < 26; j++)
			{
				if (cnt[i] == cnt[j])
				{
					ret++;
					cnt[j]--;
				}
				else
					break;
			}
		}
		//return ret;
		return 1e9+7;
	}

	void RunTest()
	{
		RunTestCase("");
		RunTestCase("a");
		RunTestCase("ab");
		RunTestCase("aab");
		RunTestCase("aaabbbcc");
		RunTestCase("ceabaacb");
	}

	void RunTestCase(string s)
	{
		cout << "Input:"<<s << endl;
		cout << "Output:"<< minDeletions(s) << endl << endl;
	}
};