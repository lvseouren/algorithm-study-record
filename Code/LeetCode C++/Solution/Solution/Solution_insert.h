#pragma once
#include "SolutionBase.h"
class Solution_insert :SolutionBase {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
	{
		if (intervals.size() == 0)
			return { newInterval };
		if (newInterval.size() == 0)
			return intervals;
		int min = intervals[0][0], max = intervals[intervals.size()-1][1];
		int x = newInterval[0];
		int y = newInterval[1];
		vector <vector<int>> ret;
		if (x < min)
		{
			if(y<min)
			{
				ret.push_back(newInterval);
				ret.insert(ret.end(), intervals.begin(), intervals.end());
			}else if(min<=y&&y<=max)
			{
				bool finded = false;
				for(int i = 0;i<intervals.size();++i)
				{
					if(finded)
					{
						ret.push_back(intervals[i]);
						continue;
					}
					int ai = intervals[i][0];
					int bi = intervals[i][1];
					if(y<ai)
					{
						ret.push_back({ x,y });
						ret.push_back({ ai,bi });
						finded = true;
						continue;
					}else if(y<=bi)
					{
						ret.push_back({ x,bi });
						finded = true;
						continue;
					}
				}
			}else
			{
				ret.push_back({x,y});
			}
		}else if(min<=x&&x<=max)
		{
			bool finded_x = false;
			bool finded_y = false;
			for (int i = 0; i < intervals.size(); ++i)
			{
				if(finded_y)
				{
					ret.push_back(intervals[i]);
					continue;
				}
				int ai = intervals[i][0];
				int bi = intervals[i][1];
				if(finded_x)
				{
					if (y < ai)
					{
						finded_y = true;
						ret.push_back({ x,y });
						ret.push_back({ ai, bi });
					}
					else if (y <= bi)
					{
						finded_y = true;
						ret.push_back({ x,bi });
					} 
				}else
				{
					if(x<ai)
					{
						finded_x = true;
					}else if(x<=bi)
					{
						x = ai;
						finded_x = true;
					}
					if(y<ai)
					{
						finded_y = true;
						ret.push_back({ x,y });
						ret.push_back({ ai,bi });
					}else if(y<=bi)
					{
						finded_y = true;
						ret.push_back({ x,bi });
					}
				}
				if(!finded_x)
					ret.push_back(intervals[i]);
			}
			if (!finded_y)
				ret.push_back({ x,y });
		}else
		{
			ret.insert(ret.begin(), intervals.begin(), intervals.end());
			ret.push_back(newInterval);
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ {11,15} }, { 15,17 });
		RunTestCase({ {11,15} }, { 2,7 });

		RunTestCase({ {11,15},{19,25} }, { 2,13 });
		RunTestCase({ {11,15},{19,25} }, { 2,17 });
		RunTestCase({ {11,15},{19,25} }, { 2,27 });

		RunTestCase({ {11,15},{19,25} }, { 11,14 });
		RunTestCase({ {11,15},{19,25} }, { 11,17 });
		RunTestCase({ {11,15},{19,25} }, { 11,23 });
		RunTestCase({ {11,15},{19,25} }, { 11,27 });

		RunTestCase({ {11,15},{19,25} }, { 26,27 });

		RunTestCase({ {1,5} }, { 2,7 });
		RunTestCase({ {1,2} }, {  });
		RunTestCase({  }, {  });
		RunTestCase({  }, { 2,5 });
		RunTestCase({ {1,3},{6,9} }, {2,5});
		RunTestCase({ {1,2},{3,5},{6,7},{8,10 },{12,16} }, { 4,8 });
	}

	void RunTestCase(vector<vector<int>> intervals, vector<int> newInterval)
	{
		cout << "Input:" << endl;
		vecPrinter->print(intervals);
		cout << "newInterval:" << endl;
		vecPrinter->print(newInterval);
		vector<vector<int>> output = insert(intervals, newInterval);
		cout << "---------Ouput:" << endl;
		vecPrinter->print(output);
		cout << endl;
	}
};