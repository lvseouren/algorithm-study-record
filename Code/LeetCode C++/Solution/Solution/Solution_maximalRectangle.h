//https://leetcode-cn.com/problems/maximal-rectangle/
//85. ������
//����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������
//
//ʾ�� :
//
//����:
//[
//	["1", "0", "1", "0", "0"],
//	["1", "0", "1", "1", "1"],
//	["1", "1", "1", "1", "1"],
//	["1", "0", "0", "1", "0"]
//]
//���: 6
#pragma once
#include <vector>
#include "Solution_largestRectangleArea.h"

using namespace std;
class Solution_maximalRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		int rowCnt = matrix.size();
		int colCnt = matrix[0].size();
		vector<int> heights(colCnt);
		int maxRect = 0;

		for(int i = 0;i<rowCnt;i++)
		{
			for (int j = 0; j < colCnt; j++)
			{
				if (matrix[i][j] == '1')
					heights[j] += 1;
				else
					heights[j] = 0;
			}
			maxRect = max(maxRect, largestRectangleArea(heights));
		}
		return maxRect;
	}

	int largestRectangleArea(vector<int>& heights)
	{
		stack<int> st;
		int cnt = heights.size();
		vector<int> left(cnt);
		vector<int> right(cnt, cnt);
		for (int i = 0; i < cnt; i++)
		{
			while (!st.empty() && heights[st.top()] >= heights[i])
			{
				right[st.top()] = i;
				st.pop();
			}
			left[i] = st.empty() ? -1 : st.top();
			st.push(i);
		}
		int ret = 0;
		for (int i = 0; i < cnt; i++)
		{
			ret = max(ret, (heights[i] * (right[i] - left[i] - 1)));
		}
		return ret;
	}

	void RunTest()
	{
		vector<vector<char>> input = { {'1','0','1','0','0'} , {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
		int ret = maximalRectangle(input);
		cout << ret << endl;
	}
};