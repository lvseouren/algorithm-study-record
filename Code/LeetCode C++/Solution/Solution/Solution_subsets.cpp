#include "Solution_subsets.h"
#include <math.h>

void VectorPrint(vector<int, allocator<int>> vec)
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

void VectorPrint(vector<vector<int>> vec)
{
	for (vector<vector<int>>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		VectorPrint(*it);
	}
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

	VectorPrint(ret);

	return ret;
}

void Solution_subsets::backtrack(vector<int>& nums, int depth)
{
	ans.push_back(oneAns);
	for (int i = depth; i < nums.size(); i++)
	{
		oneAns.push_back(nums[i]);
		backtrack(nums, i + 1);
		oneAns.pop_back();
	}
}

vector<vector<int>> Solution_subsets::subsets_backtrack(vector<int>& nums)
{
	backtrack(nums, 0);
	VectorPrint(ans);
	return ans;
}
