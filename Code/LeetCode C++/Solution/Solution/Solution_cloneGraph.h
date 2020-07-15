#pragma once
#include "Node.h"
#include <map>
#include <iostream>
class Solution_cloneGraph {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return node;
		Node* dummy;
		map<Node*, Node*> mp;
		stack<Node*> st;
		st.push(node);
		mp[node] = new Node(node->val);

		while(!st.empty())
		{
			dummy = st.top();
			st.pop();
			for (auto it:dummy->neighbors)
			{
				if(!mp[it])
				{
					st.push(it);
					mp[it] = new Node(it->val);
				}
				mp[dummy]->neighbors.push_back(mp[it]);
			}
		}

		return mp[node];
	}

	void RunTest()
	{
		Node* first = new Node(1);
		Node* second = new Node(2);
		Node* third = new Node(3);
		Node* fourth = new Node(4);
		first->neighbors.push_back(second);
		first->neighbors.push_back(fourth);
		second->neighbors.push_back(first);
		second->neighbors.push_back(third);
		third->neighbors.push_back(second);
		third->neighbors.push_back(fourth);
		fourth->neighbors.push_back(first);
		fourth->neighbors.push_back(third);

		Node* ret = cloneGraph(first);
		cout << "done" << endl;
	}
};