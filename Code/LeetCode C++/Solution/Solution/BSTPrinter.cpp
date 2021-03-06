#include "BSTPrinter.h"
#include "Solution_insertIntoBST.h"
#include <deque>
#include <math.h>
BSTPrinter::BSTPrinter()
{
	curMaxY = 0;
}

void BSTPrinter::printTab(int n)
{
	for (int i = 0; i < n; i++)
		cout << "\t";
}

void BSTPrinter::printSpace(int n)
{
	for (int i = 0; i < n; i++)
		cout << " ";
}

void BSTPrinter::print(TreeNode* root)
{
	//printBFS(root);
	int x, y;
	getxy(&x, &y);
	startY = y;
	printDFS(root, rootTabNum*8, y);
	setxy(0, curMaxY + 1);
}

void BSTPrinter::printDFS(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->val << ",";
	printDFS(root->left);
	printDFS(root->right);
}

void BSTPrinter::printDFS(TreeNode* root, int tabNum, int depth = 0)
{
	if (root == NULL)
	{
		return;
	}

	curMaxY = curMaxY < depth ? depth : curMaxY;
	setxy(tabNum, depth);
	//printSpace(tabNum);
	cout << root->val << ",";
	int offset = rootTabNum*8/pow(2, depth-startY+1);
	printDFS(root->left, tabNum-offset, depth+1);
	printDFS(root->right, tabNum+offset, depth+1);
}

void BSTPrinter::printBFS(TreeNode* root)
{
	deque<TreeNode*> queue;
	queue.push_back(root);
	while (!queue.empty())
	{
		int nums = queue.size();
		cout << endl;
		for (int i = 0; i < nums; i++)
		{
			TreeNode* p = queue.front();
			queue.pop_front();
			cout << p->val << "\t";
			if(p->left)
				queue.push_back(p->left);
			if (p->right)
				queue.push_back(p->right);
		}
	}
}

TreeNode* BSTPrinter::generateBST(vector<int> list)
{
	return generateBST(&list);
}

TreeNode* BSTPrinter::generateBST(vector<int>* list)
{
	if (list == NULL || list->size() == 0)
		return NULL;
	vector<int>::iterator it = list->begin();
	TreeNode* root = new TreeNode(*it);
	Solution_insertIntoBST s;
	while (++it != list->end())
	{
		s.insertIntoBST(root, *it);
	}
	return root;
}

TreeNode* BSTPrinter::generateTree(vector<int>* list)
{
	if (list == NULL || list->size() == 0)
		return NULL;
	vector<int>::iterator it = list->begin();
	TreeNode* root = new TreeNode(*it);
	TreeNode* dummy = root;
	deque<TreeNode*> queue;
	queue.push_back(root);
	it++;
	while (it != list->end())
	{
		if (!dummy->left)
		{
			dummy->left = new TreeNode(*it++);
			queue.push_back(dummy->left);
		}
		else if (!dummy->right)
		{
			dummy->right = new TreeNode(*it++);
			queue.push_back(dummy->right);
		}
		else
		{
			queue.pop_front();
			dummy = queue.front();
		}
	}
	return root;
}

void BSTPrinter::getxy(int* x, int* y) //该函数获取当前控制台bai光标位置
{
	CONSOLE_SCREEN_BUFFER_INFO c;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &c);
	*x = c.dwCursorPosition.X;
	*y = c.dwCursorPosition.Y;
}

void BSTPrinter::testConsolePos()
{
	int x, y;
	getxy(&x, &y);
	cout << "x=" << x << ",y=" << y<<endl;
	getxy(&x, &y);
	cout << "x=" << x << ",y=" << y;
}

void BSTPrinter::setxy(int x, int y)
{
	COORD p = { x,y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, p);
}
