//https://leetcode-cn.com/problems/maximal-square/
//221. ���������
//��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ��������������
//
//ʾ�� :
//
//����:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//��� : 4
#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_maximalSquare {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
	{
		if (matrix.empty())
			return 0;
		int rowCnt = matrix.size();
		int colCnt = matrix[0].size();
		
		int ret = 0;
		vector<int> heights(colCnt);
		for (int i = 0; i < rowCnt; i++)
		{
			for(int j = 0;j<colCnt;j++)
			{
				if (matrix[i][j] == '0')
					heights[j] = 0;
				else
					heights[j]++;
			}
			ret = max(ret, largestRectangle(heights));
		}
		return ret;
    }

	int largestRectangle(vector<int> heights)
	{
		int ret = 0;
		stack<int> st;
		int length = heights.size();
		vector<int> right(length, length);
		vector<int> left(length);
		for(int i = 0;i< length;i++)
		{
			while(!st.empty()&&heights[st.top()]>=heights[i])
			{
				right[st.top()] = i;
				st.pop();
			}
			left[i] = st.empty() ? -1 : st.top();
			st.push(i);
		}
		for(int i = 0;i<length;i++)
		{
			int maxRect = pow(min(heights[i],right[i]-left[i]-1),2);
			ret = max(ret, maxRect);
		}
		return ret;
	}

	void RunTest()
	{
		vector<vector<char>> input = { {'1','0','1','0','0'} , {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
		RunTestCase(input);
		input = {{'1', '0', '1', '1', '0', '1'}, {'1', '1', '1', '1', '1', '1'}, {'0', '1', '1', '0', '1', '1'}, {'1', '1', '1', '0', '1', '0'}, {'0', '1', '1', '1', '1', '1'}, {'1', '1', '0', '1', '1', '1'}};
		RunTestCase(input);
	}

	void RunTestCase(vector<vector<char>> input)
	{
		int ret = maximalSquare(input);
		cout << ret << endl<<endl;
	}
};