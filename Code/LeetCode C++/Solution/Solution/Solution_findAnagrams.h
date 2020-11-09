#pragma once
#include "SolutionBase.h"
class Solution_findAnagrams :SolutionBase {
public:
	vector<int> findAnagrams(string s2, string s1) 
	{
		map<char, int> groupData;
		int groupCnt = 0;
		for (int i = 0; i < s1.size(); ++i)
		{
			if (groupData.find(s1[i]) == groupData.end())
			{
				groupData[s1[i]] = 1;
				groupCnt++;
			}
			else
				groupData[s1[i]]++;
		}

		int left = 0, right = 0, curMatchGrpCnt = 0;
		map<char, int> cntDict;
		vector<int> ret;
		while (right < s2.size())
		{
			char groupId = s2[right];
			if (groupData.find(groupId) != groupData.end())
			{
				if (cntDict.count(groupId) > 0)
				{
					cntDict[groupId]++;
				}
				else
				{
					cntDict[groupId] = 1;
				}
				if (cntDict[groupId] == groupData[groupId])
					curMatchGrpCnt++;
				if (cntDict[groupId] > groupData[groupId])
				{
					while (true)
					{
						char leftGroupId = s2[left++];
						if (leftGroupId == groupId)
						{
							cntDict[leftGroupId]--;
							break;
						}
						else
						{
							if (cntDict.count(leftGroupId))
							{
								cntDict[leftGroupId]--;
								if (cntDict[leftGroupId] + 1 == groupData[leftGroupId])
									curMatchGrpCnt--;
							}
						}
					}

				}

			}
			else
			{
				cntDict.clear();
				left = right + 1;
				curMatchGrpCnt = 0;
			}

			if (curMatchGrpCnt == groupCnt)
			{
				ret.push_back(left);
				char leftGroupId = s2[left++];
				cntDict[leftGroupId]--;
				if (cntDict[leftGroupId] + 1 == groupData[leftGroupId])
					curMatchGrpCnt--;
			}
			right++;
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