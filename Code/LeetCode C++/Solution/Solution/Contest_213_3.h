#pragma once
#pragma once
#include "SolutionBase.h"
#include <algorithm>
#include <queue>

class Contest_213_3 :SolutionBase
{
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
	{
		priority_queue<int, vector<int>, greater<int>> q;
		int brickUsed = 0;
		for(int i = 1;i<heights.size();i++)
		{
			int lack = heights[i] - heights[i - 1];
			if (lack > 0)
			{	
				q.push(lack);
				if(q.size() > ladders)
				{
					brickUsed += q.top();
					q.pop();
				}
				if (brickUsed > bricks)
					return i - 1;
			}
		}
		return heights.size()-1;
		
	}

	void RunTest()
	{
		RunTestCase({ 1,13,1,1,13,5,11,11 },10,8);
		RunTestCase({ 4,2,7,6,9,14,12 }, 5, 1);
		RunTestCase({ 4,12,2,7,3,18,20,3,19 }, 10, 2);
		RunTestCase({ 14,3,19,3 }, 17, 0);
		RunTestCase({ 14,3,19,3 }, 0, 0);
		RunTestCase({ 14,3,19,3,15 }, 0, 1);
		RunTestCase({ 14,3,19,3,15 }, 0, 2);
	}

	void RunTestCase(vector<int> heights, int bricks, int ladders)
	{
		cout << "Input:";
		int output = furthestBuilding(heights, bricks, ladders);
		cout << "Output:" <<output<< endl << endl;
	}
};
