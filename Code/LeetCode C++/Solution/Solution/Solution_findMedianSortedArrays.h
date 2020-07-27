#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_findMedianSortedArrays {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> ret;
		int i1 = 0, i2 = 0;
		int cnt1 = nums1.size(), cnt2 = nums2.size();
		while(i1< cnt1 &&i2<cnt2)
		{
			if (nums1[i1] < nums2[i2])
				ret.push_back(nums1[i1++]);
			else
				ret.push_back(nums2[i2++]);
		}
		while(i1<cnt1)
		{
			ret.push_back(nums1[i1++]);
		}
		while(i2<cnt2)
		{
			ret.push_back(nums2[i2++]);
		}
		
		double mid1 = (double)cnt1 / 2;
		double mid2 = (double)cnt2 / 2;
		int mid = mid1 + mid2;
		if(cnt1%2+cnt2%2==1)
		{
			return ret[mid];
		}
		else
			return (double)ret[mid] / 2 + (double)ret[mid - 1] / 2;
	}

	void RunTest()
	{
		RunTestCase({ 1,3 }, { 2 });
		RunTestCase({ 1,2 }, { 3,4 });
		RunTestCase({ 1000 }, { 2000 });
	}

	void RunTestCase(vector<int> nums1, vector<int> nums2)
	{
		cout << findMedianSortedArrays(nums1, nums2) << endl;
	}
};