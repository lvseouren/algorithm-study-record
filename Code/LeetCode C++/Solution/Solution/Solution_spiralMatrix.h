//https://leetcode.cn/problems/spiral-matrix-iv/
#pragma once
#include "SolutionBase.h"
class Solution_spiralMatrix :SolutionBase {
public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		vector<vector<int>> ret(m, vector<int>(n, -1));

		int t = -1, l = -1, b = m, r = n;
		while (t < b && l < r && head)
		{
			auto currRow = t + 1;
			//left to right
			for (int i = l + 1; i < r; ++i)
			{
				if (head)
				{
					WriteValue(ret, currRow, i, head);
					head = head->next;
			/*		ret[currRow][i] = head->val;
					dummy = dummy->next;*/
				}
				else
					break;
			}
			t += 1;
			//top to bottom
			auto currCol = r - 1;
			for (int i = t + 1; i < b; ++i)
			{
				if (head)
				{
					WriteValue(ret, i, currCol, head);
					head = head->next;
				}
				else
					break;
			}
			r -= 1;

			//right to left
			currRow = b -1;
			for (int i = r - 1; i > l; --i)
			{
				if (head)
				{
					WriteValue(ret, currRow, i, head);
					head = head->next;
				}
				else
					break;
			}
			b -= 1;
			//bottom to top
			currCol = l + 1;
			for (int i = b - 1; i > t; --i)
			{
				if (head)
				{
					WriteValue(ret, i, currCol, head);
					head = head->next;
					/*ret[i][currCol] = node->val;
					dummy = dummy->next;*/
				}
				else
					break;
			}
			l += 1;
		}
		return ret;
	}

	void WriteValue(vector<vector<int>>& matrix, int m, int n, ListNode* node)
	{
		cout << "m = "<<m << ",n =" << n << ",value = " << node->val<<endl;
		matrix[m][n] = node->val;
	}

	void RunTest()
	{
		ListNode* node = new ListNode({ 3,0,2,6,8,1,7,9,4,2,5,5,0 });
		RunTestCase(3, 5, node);
	}

	void RunTestCase(int m, int n, ListNode* head)
	{
		cout << "Input:" << endl;
		auto output = spiralMatrix(m, n, head);
		vecPrinter->print(output);
	}
};