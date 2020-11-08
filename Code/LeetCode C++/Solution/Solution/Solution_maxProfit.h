#pragma once
#include "SolutionBase.h"
typedef long long  ll;

class Solution_maxProfit :SolutionBase {
public:
	int maxProfit(vector<int>& inventory, int orders) 
	{
		ll sum = 0;
		vector<int> realInventory;
		ll average = INT_MAX;
		vector<int>* frontBuffer = &inventory;
		vector<int>* backBuffer = &realInventory;
		vector<int>* finalData;
		while(true)
		{
			finalData = frontBuffer;
			backBuffer->clear();

			sum = 0;
			int cnt = frontBuffer->size();
			for (int i = 0; i < cnt; ++i)
			{
				sum += (*frontBuffer)[i];
			}
			ll rest = sum - orders;
			average = ceil(rest * 1.0 / cnt);
			
			bool canBreak = true;
			for (int i = 0; i < cnt; ++i)
			{
				if ((*frontBuffer)[i] < average)
				{
					canBreak = false;
					break;
				}
			}
			if (canBreak)
				break;

			for (int i = 0; i < cnt; ++i)
			{
				if ((*frontBuffer)[i] >= average)
				{
					backBuffer->push_back((*frontBuffer)[i]);
				}
			}
			auto tmp = frontBuffer;
			frontBuffer = backBuffer;
			backBuffer = tmp;
		}

		int cnt = finalData->size();
		ll d = sum - average * cnt;
		ll differ = orders - d;
		ll ret = 0;
		int modular = 1e9 + 7;
		for(int i = 0;i<cnt;++i)
		{
			long long curPrice = (*finalData)[i];

			long long tmp1 = (curPrice + average + 1) ;
			long long tmp2 = (curPrice - average) ;
			if (tmp1 % 2 == 0)
				tmp1 /= 2;
			else
				tmp2 /= 2;
			long long price = mod_mult(tmp1, tmp2, modular);
			price %= modular;
			ret += price;
			ret %= modular;
		}
		ret += average * differ;
		ret %= modular;
		return ret;
	}

	ll mod_mult(ll a, ll b, ll mod) {
		a %= mod;
		b %= mod;
		ll ans = 0;
		while (b > 0) {
			if (b & 1) {
				ans += a;
				if (ans >= mod)
					ans -= mod;
			}
			a <<= 1;
			if (a >= mod) a = a - mod;
			b >>= 1;
		}
		return ans;
	}

	void RunTest()
	{
		RunTestCase({701695700, 915736894, 35093938, 364836059, 452183894, 951826038, 861556610, 441929847, 842650446, 858413011, 457896886, 35119509, 776620034, 396643588, 83585103, 681609037},598226067);
		RunTestCase({ 680754224, 895956841, 524658639, 3161416, 992716630, 7365440, 582714485, 422256708, 332815744, 269407767 }, 707568720);
		RunTestCase({ 2,5 }, 4);
		RunTestCase({ 3,5 }, 6);
		RunTestCase({ 2,8,4,10,6 }, 20);
		RunTestCase({ 1000000000 }, 1000000000);
		RunTestCase({ 773160767}, 252264991);
		RunTestCase({ 497978859,167261111,483575207,591815159 }, 836556809);
	}

	void RunTestCase(vector<int> inventory, int orders)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< maxProfit(inventory, orders) << endl << endl;
	}
};
