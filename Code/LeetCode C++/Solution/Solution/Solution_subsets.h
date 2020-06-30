#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution_subsets {
public:
	Solution_subsets();
	vector<vector<int>> subsets(vector<int>& nums);
	vector<vector<int>> subsets_backtrack(vector<int>& nums);
private:
	void backtrack(vector<int>&, int);
	vector<vector<int>> ans;
	vector<int> oneAns;
};