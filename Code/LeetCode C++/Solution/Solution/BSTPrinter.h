#pragma once
#include "TreeNode.h"
#include <windows.h>
class BSTPrinter
{
public:
	BSTPrinter();
	void printTab(int n);
	void printSpace(int n);
	void print(TreeNode* node);
	void printDFS(TreeNode* root);
	void printDFS(TreeNode* root, int tabNum, int depth);
	void printBFS(TreeNode* root);
	TreeNode* generateBST(vector<int>* list);
	void testConsolePos();
	void setxy(int x, int y);
private:
	void getxy(int* x, int* y);
	const int rootTabNum = 7;
	int curMaxY;
	int startY;
};

