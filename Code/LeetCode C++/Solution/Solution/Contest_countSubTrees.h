#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "SolutionBase.h"
using namespace std;
class Contest_countSubTrees:SolutionBase {
public:
	struct TreeNode
	{
		TreeNode(char value)
		{
			val = value;
		}
		char val;
		vector<TreeNode*> childs;
		void addChild(TreeNode* child)
		{
			childs.push_back(child);
		}
	};

	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
	{
		map<int, TreeNode*> nodeDict;
		map<int, bool> hasFather;
		for(auto edge:edges)
		{
			//sort(edge.begin(),edge.end());
			int val1 = edge[0];
			int val2 = edge[1];
			TreeNode* node1 = nodeDict[val1];
			if (!node1)
			{
				node1 = new TreeNode(labels[val1]);
				nodeDict[val1] = node1;
			}
			TreeNode* node2 = nodeDict[val2];
			if (!node2)
			{
				node2 = new TreeNode(labels[val2]);
				nodeDict[val2] = node2;
			}
			if (val1 == 0 || hasFather[val1])
			{
				node1->addChild(node2);
				hasFather[val2] = true;
			}
			else
			{
				node2->addChild(node1);
				hasFather[val1] = true;
			}

		}

		vector<int> ret;
		for(int i = 0;i<n;++i)
		{
				ret.push_back(getCount(nodeDict[i], labels[i]));
		}
		return ret;
	}

	int getCount(TreeNode* root, char c)
	{
		if (root == NULL)
			return 0;

		int ret = root->val == c?1:0;
		for(auto child:root->childs)
			ret += getCount(child, c);
		return ret;
	}

	void RunTest()
	{
		RunTestCase(4, {{0, 2}, {0, 3}, {1, 2}}, "aeed");
		RunTestCase(5, {{0, 1}, {0, 2}, {1, 3}, {0, 4}}, "aabab");
		RunTestCase(6, {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {4, 5}}, "cbabaa");
		RunTestCase(7, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}, "aaabaaa");
	}

	void RunTestCase(int n,vector<vector<int>> edges, string labels)
	{
		vector<int> output = countSubTrees(n, edges, labels);
		vecPrinter->print(output);
		cout << endl;
	}
};