#pragma once
#include "SolutionBase.h"
#include <unordered_set>
struct pos
{
	pos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int GetPriority(pos desPos)
	{
		return GetNodeGValue() + GetHValue(desPos);
	}

	int GetNodeGValue()
	{
		return parent ? parent->GetNodeGValue() + GetDistanceToParent() : 0;
	}

	int GetHValue(pos desPos)
	{
		return abs(desPos.x - x) + abs(desPos.y - y);
	}

	int GetDistanceToParent()
	{
		if (parent == NULL)
			return 0;
		if (x != parent->x && y != parent->y)
			return 14;
		else
			return 10;
	}

	void SetParent(pos* p)
	{
		parent = p;
	}

	pos* GetParent()
	{
		return parent;
	}

	vector<pos> GetNeighbours(int max, unordered_set<pos> closeSet)
	{
		vector<pos> ret;
		for(int i = x-1;i<=x+1;++i)
			for (int j = y - 1; j <= y + 1; ++j)
			{
				pos p = pos(i, j);
				if (i >= 0 && j >= 0 && i < max && j < max && (x + y != i + j)&&closeSet.find(p)==closeSet.end())
				{
					ret.push_back(p);
				}
			}
		return ret;
	}

	bool Equal(pos p)
	{
		return x == p.x && y == p.y;
	}

	void print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
	int x;
	int y;
	pos* parent;
};

class Solution_astar :SolutionBase {
public:
	vector<pos> pathfinding(vector<vector<int>> map, pos from, pos to)
	{
		vector<pos> ret;
		deque<pos> openList;
		unordered_set<pos> closeSet;
		//起点加入到open list
		openList.push_back(from);
		//遍历open list，检查每个node的相邻节点，如果可达并且不在close list中则加入到open list
		while (!openList.empty())
		{
			int curMinPriority = INT_MAX;
			pos* bestNode;
			int nodeIndex;
			for (int i = 0; i < openList.size(); ++i)
			{
				pos node = openList[i];
				int priority = node.GetPriority(to);
				if (priority < curMinPriority)
				{
					nodeIndex = i;
					bestNode = &openList[i];
				}
			}
			
			if (bestNode->Equal(to))
			{
				pos* node = bestNode;
				while (node)
				{
					ret.push_back(*node);
					node = node->GetParent();
				}
				return ret;
			}
			else
			{
				openList.erase(openList.begin()+nodeIndex);
				closeSet.insert(*bestNode);
				vector<pos> neibors = bestNode->GetNeighbours(map.size(), closeSet);
				for (int i = 0; i < neibors.size(); ++i)
					openList.push_back(neibors[i]);
			}
		}
		//
		return ret;
	}

	void RunTest()
	{
		RunTestCase({ {0,0,0,0} ,{0,0,1,0},{0,0,1,0},{0,0,1,0} });
	}

	void RunTestCase(vector<vector<int>> map)
	{
		auto path = pathfinding(map, pos(3,1), pos(3,3));
		for (int i = 0; i < path.size(); ++i)
			path[i].print();
		cout << endl;
	}
};