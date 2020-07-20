#pragma once
#include <iostream>
using namespace std;
class Solution_numWaterBottles {
public:
	int numWaterBottles(int numBottles, int numExchange) 
	{
		int ret = numBottles;
		int numEmptyBottles = ret;
		while (numEmptyBottles / numExchange >= 1)
		{
			int num = numEmptyBottles / numExchange;
			ret += num;
			numEmptyBottles = num + numEmptyBottles % numExchange;
		}
		return ret;
	}

	void RunTest()
	{
		RunTestCase(9, 3);
		RunTestCase(15, 4);
	}

	void RunTestCase(int numBottles, int numExchange)
	{
		cout << "ÊäÈë:numBottles = " << numBottles << ",numExchange = " << numExchange << endl;
		int output = numWaterBottles(numBottles, numExchange);
		cout << "Êä³ö:" << output << endl;
	}
};