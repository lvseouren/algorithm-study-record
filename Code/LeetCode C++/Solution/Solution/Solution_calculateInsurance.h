#pragma once
#include "SolutionBase.h"
class Solution_calculateInsurance :SolutionBase {
public:
	//����Ǯ��ָ��ͨ���ʵ�����£���n�����ֵ
	float calculateMoneyTimeValue(int currentMoney, int year, float inflationRate)
	{
		return currentMoney / pow(1 + inflationRate, year+1);
	}

	//��n�걣����ֵ
	float calculatePremium(int firstYearCost, int years, float inflationRate)
	{
		return calculateMoneyTimeValue(firstYearCost, years, inflationRate);
	}

	//������ֵ
	float calculateSumAssured(int sumAssured, int year, float inflationRate)
	{
		return sumAssured / pow(1 + inflationRate, year);
	}

	//�ܸ���
	float calculateLeverage(float cost, float sumAssured)
	{
		return cost / sumAssured;
	}

	void RunTest()
	{
		//RunTestCase(8585, 30, 500000, 0.05);//test1- ����ͨ���ʣ�5%
		//RunTestCase(10985, 20, 500000, 0.05);//test1- ����ͨ���ʣ�5%
		RunTestCase(5379, 30, 300000, 0.05);//���������ػ���Ӣ�۰棩- ����ͨ���ʣ�5%
		RunTestCase(5379, 30, 300000, 0.02);//���������ػ���Ӣ�۰棩- ����ͨ���ʣ�2%
		RunTestCase(5379, 30, 300000, 0);//���������ػ���Ӣ�۰棩- ����ͨ���ʣ�0%
	}

	void RunTestCase(int firstYearCost, int years, int sumAssured, float inflationRate)
	{
		cout << "-----------------------------------------" << endl;
		cout << "���걣��:" << firstYearCost << ",�ɷ�����:" << years << ",����:" << sumAssured <<",ͨ����:"<<inflationRate*100<<"%"<< endl<<endl;
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
			cout << "��" << i + 1 << "��" << "������ֵ:" << value << ";";
			cout << "��" << i + 1 << "��" << "������ֵ:" << assured << endl;
			sum += value;
		}
		cout << "�ܱ�����ֵ��" << sum << endl;
	}
};
