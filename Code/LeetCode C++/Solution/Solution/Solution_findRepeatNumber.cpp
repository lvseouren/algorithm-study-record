#include <vector>
#include <map>
#include <iostream>
#include "Solution_findRepeatNumber.h"


Solution_findRepeatNumber::Solution_findRepeatNumber()
{
}

int Solution_findRepeatNumber::findRepeatNumber(std::vector<int>& nums) 
{
	std::map<int, bool> table;
	for (int i = 0; i < nums.size(); i++)
	{
		int num = nums[i];
		if (table[num])
		{
			std::cout << num << "\n";
			return num;
		}
		else
		{
			table[num] = true;
		}
	}
}
