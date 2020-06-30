#include "Solution_subsets.h"
#include <math.h>

void VectorPrint(vector<int> vec)
{
	cout << "[";
	if(vec.size() == 0)
	{
		cout << "]"<<endl;
		return;
	}
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (it + 1 != vec.end())
			cout << *it << ",";
		else
			cout << *it << "]";
	}
	cout << "\n";
}

vector<int> ConvertToBinaryNum(int num)
{
	vector<int> ret;
	while (num != 0)
	{
		ret.push_back(num % 2);
		num /= 2;
	}
	return ret;
}

Solution_subsets::Solution_subsets()
{

}

vector<vector<int>> Solution_subsets::subsets(vector<int>& nums)
{
	vector<vector<int>> ret(pow(2,nums.size()));
	int index = 0;
	for(int i = 0;i<pow(2,nums.size());i++)
	{
		vector<int> temp = ConvertToBinaryNum(i);
		vector<int> element;
		for(int j = temp.size()-1;j>=0;j--)
		{
			if(temp[j] == 1)
				element.push_back(nums[j]);
		}
		ret[index++] = element;
	}

	for(vector<vector<int>>::iterator it = ret.begin();it!=ret.end();++it)
	{
		VectorPrint(*it);
	}
	return ret;
}