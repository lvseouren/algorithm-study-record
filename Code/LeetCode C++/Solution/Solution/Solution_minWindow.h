//76. ��С�����Ӵ�
//����һ���ַ��� S��һ���ַ��� T ���������һ���㷨�������� O(n) ��ʱ�临�Ӷ��ڣ����ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
//�����732������ͬ��֮��
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

		int lackCount = dict.size();//��lackCountΪ0ʱ��˵�������ڰ�����t���е�Ԫ��
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