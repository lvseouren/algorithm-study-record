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

		map<Node*, int> oldNodeToIndex;
		map<int, Node*> indexToNewNode;
		stack<Node*> st;
		st.push(node);
		while(!st.empty())
		{
			dummy = st.top();
			st.pop();
			oldNodeToIndex[dummy] = dummy->val;
			indexToNewNode[dummy->val] = new Node(dummy->val);
			for (vector<Node*>::iterator it = dummy->neighbors.begin(); it != dummy->neighbors.end(); ++it)
			{
				if (!oldNodeToIndex[*it])
					st.push(*it);
			}
		}

		for (std::map<Node*, int>::iterator iter = oldNodeToIndex.begin(); iter != oldNodeToIndex.end(); ++iter)
		{
			Node* temp = iter->first;
			Node* newNode = indexToNewNode[temp->val];
			for(vector<Node*>::iterator it = temp->neighbors.begin();it != temp->neighbors.end();++it)
			{
				newNode->neighbors.push_back(indexToNewNode[(*it)->val]);
			}
		}
		return indexToNewNode[1];
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