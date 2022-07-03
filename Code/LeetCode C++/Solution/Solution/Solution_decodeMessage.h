#pragma once
#include "SolutionBase.h"
class Solution_decodeMessage :SolutionBase {
public:
	string decodeMessage(string key, string message) {
		unordered_map<char, char> dict;
		int currOffset = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			char tmp = key[i];
			if (key[i] != ' ')
			{
				if (dict.find(key[i]) == dict.end())
				{
					dict[key[i]] = 'a' + currOffset;
					currOffset++;
					if (currOffset > 26)
						break;
				}
			}
		}
		for (int i = 0; i < message.length(); ++i)
		{
			char tmp = message[i];
			if(tmp != ' ')
				message[i] = dict[tmp];
		}
		return message;
	}

	void RunTest()
	{
		RunTestCase("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");
	}

	void RunTestCase(string key, string message)
	{
		cout << "Input:" << endl;
		cout << "Output:" << decodeMessage(key, message) << endl;
	}
};