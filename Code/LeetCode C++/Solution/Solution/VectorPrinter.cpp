#include "VectorPrinter.h"

VectorPrinter::VectorPrinter()
{
}

void VectorPrinter::print(vector<int> vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << ",";
	cout << endl;
}

void VectorPrinter::print(vector<vector<int>> vec)
{
	for (vector<vector<int>>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		for (vector<int>::iterator i = it->begin(); i != it->end(); ++i)
			cout << *i << ",";
		cout << endl;
	}
}
