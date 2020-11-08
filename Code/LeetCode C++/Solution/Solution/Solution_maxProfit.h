#pragma once
#include "SolutionBase.h"
typedef long long  ll;

class Solution_maxProfit :SolutionBase {
public:
	int maxProfit(vector<int>& inventory, int orders) 
	{
		ll sum = 0;
		int cnt = inventory.size();
		for (int i = 0; i < cnt; ++i)
			sum += inventory[i];
		ll rest = sum - orders;
		ll average = ceil(rest*1.0 / cnt);
		ll d = sum - average * cnt;
		ll differ = orders - d;
		ll ret = 0;
		int modular = 1e9 + 7;
		for(int i = 0;i<cnt;++i)
		{
			long long curPrice = inventory[i];
			//for (int j = 0; j < inventory[i] - average; ++j)
			//{
			//	ret += curPrice;
			//	curPrice--;
			//	ret %= modular;
			//}

			long long tmp1 = (curPrice + average + 1) ;
			long long tmp2 = (curPrice - average) ;
			long long price = mod_mult(tmp1, tmp2, modular);
			price /= 2;
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
		//RunTestCase({ 2,5 }, 4);
		//RunTestCase({ 3,5 }, 6);
		//RunTestCase({ 2,8,4,10,6 }, 20);
		//RunTestCase({ 1000000000 }, 1000000000);
		//RunTestCase({ 773160767}, 252264991);
		RunTestCase({ 497978859,167261111,483575207,591815159 }, 836556809);
	}

	void RunTestCase(vector<int> inventory, int orders)
	{
		cout << "Input:" << endl;
		cout << "Output:"<< maxProfit(inventory, orders) << endl << endl;
	}
};
