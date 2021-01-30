#pragma once
#include "SolutionBase.h"
class Solution_calculateInsurance :SolutionBase {
public:
	//计算钱在指定通胀率的情况下，第n年的现值
	float calculateMoneyTimeValue(int currentMoney, int year, float inflationRate)
	{
		return currentMoney / pow(1 + inflationRate, year+1);
	}

	//第n年保费现值
	float calculatePremium(int firstYearCost, int years, float inflationRate)
	{
		return calculateMoneyTimeValue(firstYearCost, years, inflationRate);
	}

	//保额现值
	float calculateSumAssured(int sumAssured, int year, float inflationRate)
	{
		return sumAssured / pow(1 + inflationRate, year);
	}

	//杠杆率
	float calculateLeverage(float cost, float sumAssured)
	{
		return cost / sumAssured;
	}

	void RunTest()
	{
		//RunTestCase(8585, 30, 500000, 0.05);//test1- 假设通胀率：5%
		//RunTestCase(10985, 20, 500000, 0.05);//test1- 假设通胀率：5%
		RunTestCase(5379, 30, 300000, 0.05);//如意人生守护（英雄版）- 假设通胀率：5%
		RunTestCase(5379, 30, 300000, 0.02);//如意人生守护（英雄版）- 假设通胀率：2%
		RunTestCase(5379, 30, 300000, 0);//如意人生守护（英雄版）- 假设通胀率：0%
	}

	void RunTestCase(int firstYearCost, int years, int sumAssured, float inflationRate)
	{
		cout << "-----------------------------------------" << endl;
		cout << "首年保费:" << firstYearCost << ",缴费年限:" << years << ",保额:" << sumAssured <<",通胀率:"<<inflationRate*100<<"%"<< endl<<endl;
		PrintYearlyPresentValue(firstYearCost, years, inflationRate, sumAssured);
		cout << "-----------------------------------------" << endl;
	}

	void PrintYearlyPresentValue(int firstYearCost, int years, float inflationRate, int sumAssured)
	{
		int sum = 0;
		for (int i = 0; i < years; ++i)
		{
			int value = calculateMoneyTimeValue(firstYearCost, i, inflationRate);
			int assured = calculateSumAssured(sumAssured, i, inflationRate);
			cout << "第" << i + 1 << "年" << "保费现值:" << value << ";";
			cout << "第" << i + 1 << "年" << "保额现值:" << assured << endl;
			sum += value;
		}
		cout << "总保费现值：" << sum << endl;
	}
};
