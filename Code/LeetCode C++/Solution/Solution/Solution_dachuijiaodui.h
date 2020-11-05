//https://www.nowcoder.com/test/question/42852fd7045c442192fa89404ab42e92?pid=16516564&tid=39164828
//输入描述:
//第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。
//
//后面跟随N行，每行为一个待校验的字符串。
//
//输出描述 :
//N行，每行包括一个被修复后的字符串。

#pragma once
#include "SolutionBase.h"
class Solution_dachuijiaodui :SolutionBase {
public:
	vector<string> f(int n,vector<string> inputs)
	{
		vector<string> ret;
		int len = inputs.size();
		for(int i = 0;i<inputs.size();++i)
		{
			ret.push_back(process(inputs[i]));
		}
		return ret;
	}

	string process(string s)
	{
		int len = s.size();
		if (len <= 2)
			return s;
		char beforePre = s[0];
		char pre = s[1];
		string ret;
		ret.push_back(beforePre);
		ret.push_back(pre);
		for(int i = 2;i<len;++i)
		{
			if(pre==beforePre)
			{
				if(s[i]==pre)
					continue;
				else
				{
					if(i<len-1&&s[i]==s[i+1])
					{
						beforePre = pre;
						pre = i;
						ret.push_back(s[i]);
						i = i + 2;
						continue;
					}
				}
			}

			ret.push_back(s[i]);
			beforePre = pre;
			pre = s[i];
		}
		return ret;
	}

	void RunTest()
	{
		//RunTestCase(2, {"helloo","wooooooow"});
		RunTestCase(3, { "helloo","helllo","wooooow" });
	}

	void RunTestCase(int n, vector<string> inputs)
	{
		cout << "Input:" << endl;
		vecPrinter->print(inputs);
		cout << endl << "Output:" << endl;
		auto output = f(n, inputs);
		vecPrinter->print(output);
		cout << endl;
	}
};