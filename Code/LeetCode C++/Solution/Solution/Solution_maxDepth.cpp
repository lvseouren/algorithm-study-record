#include "Solution_maxDepth.h"
#include <stack>
using namespace std;

Solution_maxDepth::Solution_maxDepth()
{
}

int Solution_maxDepth::maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}

int Solution_maxDepth::maxDepth_iterate_dfs(TreeNode* root)
{
	if (root == NULL)return 0;
	stack<pair<TreeNode*, int>> s;
	int depth = 0;
	TreeNode* p = root;
	int maxDepth = 0;
	while(!s.empty()||p!=NULL)
	{
		while(p!=NULL)
		{
			s.push(pair<TreeNode*, int>(p, ++depth));
			p = p->left;
		}
		if (maxDepth < depth) maxDepth = depth;
		p = s.top().first;
		depth = s.top().second;
		s.pop();
		p = p->right;
	}
	return maxDepth;
}

int Solution_maxDepth::maxDepth_iterate_bfs(TreeNode* root)
{
	if (root == NULL)return 0;
	deque<TreeNode*> q;
	q.push_back(root);
	int depth = 0;
	while (!q.empty())
	{
		depth++;
		int num = q.size();
		for (int i = 0; i < num; i++)
		{
			TreeNode* p = q.front();
			q.pop_front();
			if (p->left)
				q.push_back(p->left);
			if (p->right)
				q.push_back(p->right);
		}
	}
	return depth;
}