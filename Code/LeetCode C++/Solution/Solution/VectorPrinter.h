#pragma once
#include <vector>
#include <iostream>
using namespace std;

class VectorPrinter
{
public:
	VectorPrinter(){}

	template<typename T>
	void print(vector<T>& vec)
	{
		for (auto it : vec)
			cout << it << ",";
		cout << endl;
	}

	void print(vector<vector<int>> vec)
	{
		for (vector<vector<int>>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			for (vector<int>::iterator i = it->begin(); i != it->end(); ++i)
				cout << *i << ",";
			cout << endl;
		}
	}

};

