#pragma once
#include "SolutionBase.h"
class Solution_ladderLength :SolutionBase {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
	{

	}

	void RunTest()
	{
		RunTestCase("hit", "cog", { "cog" });
		RunTestCase("hit", "cog", {  });
		RunTestCase("hit", "cog", { "hog","cog" });
		RunTestCase("hit", "cog", { "hot","cog" });
		RunTestCase("hit", "cog", {"hot","dot","dog","lot","log","cog"});
		RunTestCase("hit", "cog", { "hot","dot","dog","lot","log" });
	}

	void RunTestCase(string beginWord, string endWord, vector<string> wordList)
	{
		cout << "Input:beginWord="<<beginWord<<",endWord="<<endWord << endl;
		vecPrinter->print(wordList);
		cout << endl;
		cout << "Output:"<< ladderLength(beginWord, endWord, wordList) << endl << endl;
	}
};