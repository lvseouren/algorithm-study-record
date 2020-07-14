#pragma once
#include <string>
#include <stack>
using namespace std;
class Solution_decodeString
{
public:
	string decodeString(string s) 
	{
		stack<string> st;
		
		for(int i = 0;i<s.length();i++)
		{
			if(s[i] == ']')
			{
				string temp;
				while(st.top()!= "[")
				{
					temp.insert(0,st.top());
					st.pop();
				}
				st.pop();
				string numStr;
				while(!st.empty() && isNumber(st.top().c_str()[0]))
				{
					numStr.insert(0, st.top());
					st.pop();
				}
				int count = stoi(numStr);
				string extendStr;
				for (int j = 0; j < count; j++)
				{
					extendStr.append(temp);
				}
				st.push(extendStr);
			}else
			{
				st.push(string(1,s[i]));
			}
		}
		string ret;
		while(!st.empty())
		{
			ret.insert(0, st.top());
			st.pop();
		}
		return ret;
	}

	bool isNumber(char c)
	{
		int charNum = (int)c;
		int charZero = (int)'0';
		int num = charNum - charZero;
		return num>=0 && num <=9;
	}

	void RunTest()
	{
		//RunTestCase("3[a2[c]]", "accaccacc");
		//RunTestCase("3[a]2[bc]", "aaabcbc");
		//RunTestCase("2[abc]3[cd]ef", "abcabccdcdcdef");
		//RunTestCase("abc3[cd]xyz", "abccdcdcdxyz");
		RunTestCase("100[leetcode]", "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode");
	}

	void RunTestCase(string input, string expectOutput)
	{
		cout << "输入:" << input << endl;
		string output = decodeString(input);
		cout << "预期输出：" << expectOutput<<endl;
		cout << "实际输出：" << output << endl;
		cout << endl;
	}
};

