#pragma once
#include <vector>
#include <string>
#include <map>
#include "SolutionBase.h"
using namespace std;
class Contest_maxNumOfSubstrings:SolutionBase {
public:
	vector<string> ret;
	vector<string> maxNumOfSubstrings(string s) 
	{
		vector<string> ret;
		if (s.empty())
			return ret;
		map<char, int> left;
		map<char, int> right;
		for (int i = 0; i < s.length(); i++)
		{
			if (left.find(s[i]) == left.end())
				left[s[i]] = i;
			right[s[i]] = i;
		}
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (left.find(c) != left.end())
			{
				if (left[c] == right[c])
				{
					ret.push_back(string(1, c));
				}
				else
				{
					bool skip = false;
					for (int i = left[c] + 1; i < right[c]; i++)
					{
						if (left[s[i]] < left[c])
						{
							skip = true;
							break;
						}

						if (right[s[i]] < right[c])
						{
							skip = true;
							break;
						}
						right[c] = right[s[i]];
					}
					if (!skip)
						ret.push_back(s.substr(left[c], right[c] - left[c] + 1));
				}
			}
		}
		if (ret.empty())
			ret.push_back(s);
		return ret;
	}

	vector<string> recursiveFunc(string& s, map<char,int>& left, map<char,int>& right, int start, int end)
	{
		vector<string> curRet;
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (left.find(c) != left.end())
			{
				if (left[c] < start||right[c]>end)
					return curRet;
				if (left[c] == right[c])
				{
					ret.push_back(string(1, c));
				}
				else
				{
					bool skip = false;
					for (int i = left[c] + 1; i < right[c]; i++)
					{
						if (left[s[i]] < left[c])
						{
							skip = true;
							break;
						}

						if (right[s[i]] < right[c])
						{
							vector<string> temp = recursiveFunc(s, left, right, left[c],right[s[i]]);
							if (!temp.empty())
							{
								skip = true;
								break;
							}
						}
						right[c] = right[s[i]];
					}
					if (!skip)
						ret.push_back(s.substr(left[c], right[c] - left[c] + 1));
				}
			}
		}
	}

	void RunTest()
	{
	/*	RunTestCase("adefaddaccc");
		RunTestCase("abbaccd");
		RunTestCase("abab");*/
		RunTestCase("ababa"); 
	}

	void RunTestCase(string input)
	{
		ret.clear();
		cout << "input=" << input << endl;
		auto ret = maxNumOfSubstrings(input);
		vecPrinter->print(ret);
		cout << endl;
	}
};