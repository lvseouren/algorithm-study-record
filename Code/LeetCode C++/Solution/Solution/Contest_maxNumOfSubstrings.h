#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "SolutionBase.h"
using namespace std;
class Contest_maxNumOfSubstrings:SolutionBase {
public:
	struct Seg 
	{
		Seg(int lf,int rt)
		{
			left = lf;
			right = rt;
		}
		int left, right;
		bool operator <(const Seg& rhs) const
		{
			if (rhs.right == right)
				return left > rhs.left;
			return right < rhs.right;
		}
	};
	vector<string> maxNumOfSubstrings(string s)
	{
		vector<Seg> seg(26, Seg( -1, -1 ));
		for (int i = 0; i < s.length(); ++i)
		{
			int char_idx = s[i] - 'a';
			if(seg[char_idx].left == -1)
				seg[char_idx].left = i;
			seg[char_idx].right = i;
		}
		for(int i = 0;i<26;++i)
		{
			if(seg[i].left!=-1)
			{
				for (int j = seg[i].left; j <= seg[i].right; ++j)
				{
					int char_idx = s[j] - 'a';
					if(seg[i].left <= seg[char_idx].left && seg[char_idx].right <= seg[i].right)
						continue;

					seg[i].left = min(seg[i].left, seg[char_idx].left);
					seg[i].right = max(seg[i].right, seg[char_idx].right);
					j = seg[i].left;
				}
			}
		}

		sort(seg.begin(), seg.end());
		vector<string> ans;
		int end = -1;
		for(auto& segment:seg)
		{
			int left = segment.left, right = segment.right;
			if(left == -1)
				continue;
			if(end == -1||left>end)
			{
				end = right;
				ans.emplace_back(s.substr(left, right - left + 1));
			}
		}
		return ans;
	}

	void RunTest()
	{
		RunTestCase("adefaddaccc");
		RunTestCase("abbaccd");
		RunTestCase("abab");
		RunTestCase("ababa"); 
	}

	void RunTestCase(string input)
	{
		cout << "input=" << input << endl;
		auto ret = maxNumOfSubstrings(input);
		vecPrinter->print(ret);
		cout << endl;
	}
};