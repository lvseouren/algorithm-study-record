#pragma once
#include "SolutionBase.h"
#include <queue>
class HuffmanTreeNode
{
public:
	HuffmanTreeNode(char v, int w)
	{
		c = v;
		weight = w;
		code = "";
	}
	int weight;
	char c;
	string code;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
};

class Solution_genHuffmanCode :SolutionBase {
public:
	map<char,string> genHuffmanCode(map<char, int> input)
	{
		// Declare vector of pairs 
		vector<pair<char, int> > A;

		// Copy key-value pair from Map 
		// to vector of pairs 
		//for (auto& it : input) {
		//	A.push_back(it);
		//}
		//sort(A.begin(), A.end(), [](pair<string, int>& a, pair<string, int>& b) {
		//	return a.second < b.second;
		//	});
		
		//生成huffman tree
		queue<HuffmanTreeNode*> nodeQueue;
		auto it = input.begin();
		while (it != input.end())
		{
			HuffmanTreeNode* curNode = new HuffmanTreeNode(it->first, it->second);
			nodeQueue.push(curNode);

			if (nodeQueue.size() == 2)
			{
				auto left = nodeQueue.front();
				nodeQueue.pop();
				auto right = nodeQueue.front();
				nodeQueue.pop();
				HuffmanTreeNode* parent = new HuffmanTreeNode('\0', left->weight+right->weight);
				parent->left = left;
				parent->right = right;
				nodeQueue.push(parent);
			}
			
			it++;
		}
		HuffmanTreeNode* root = nodeQueue.front();
		//生成编码
		map<char, string> ret;
		for (auto& it : input) {
			ret[it.first] = "";
		}

		generate(root, ret);
		return ret;
	}

	void generate(HuffmanTreeNode* root, map<char, string>& ret)
	{
		if (root == NULL)
			return;

		if(root->left)
			root->left->code = root->code + "0";
		if(root->right)
			root->right->code = root->code + "1";
		if (root->c != '\0')
		{
			ret[root->c] = root->code;
		}
		generate(root->left,ret);
		generate(root->right,ret);
	}

	void RunTest()
	{
		RunTestCase({ {'a',1},{'b',3},{'c',5},{'d',15} });
	}

	void RunTestCase(map<char,int> input)
	{
		cout << "Input:" << endl;
		auto output = genHuffmanCode(input);
		for (auto item : output)
		{
			cout << item.first << " 编码为:" << item.second<<endl;
		}
		cout << endl;
	}
};