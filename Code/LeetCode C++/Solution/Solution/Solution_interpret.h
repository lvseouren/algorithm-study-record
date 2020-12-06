#pragma once
#include "SolutionBase.h"
class Solution_interpret :SolutionBase
{
public:
	string interpret(string command) 
	{
		string ret = "";
		for(int i = 0;i<command.size();++i)
		{
			char c = command[i];
			if(c == 'G')
			{
				ret.push_back(c);
			}
			else if (c == ')')
			{
				if (command[i - 1] == '(')
					ret.push_back('o');
				else
					ret.append("al");
			}
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase("G()(al)");
		RunTestCase("G()()()()(al)");
		RunTestCase("(al)G(al)()()G");
	}

	void RunTestCase(string command)
	{
		cout << "Input:"<<command<<endl;
		auto output = interpret(command);
		cout << "Output:" << output<<endl << endl;
	}
};