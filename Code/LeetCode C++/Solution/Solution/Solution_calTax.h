#pragma once
#include "SolutionBase.h"
struct TaxData
{
	TaxData(float a, float b)
	{
		tax = a;
		taxRate = b;
	}
	float tax;
	float taxRate;
};
class Solution_calTax :SolutionBase {
	int c;
	float taxRate_a;
	float taxRate_b;
public:
	float calMinTax(float a, float b)
	{
		float ret = INT_MAX;
		for(int i = 0;i<=b;++i)
		{
			TaxData tax_a = GetTaxOfA(a + i);
			TaxData tax_b = GetTaxOfB(b - i);
			int curTax = tax_a.tax + tax_b.tax;
			if (curTax < ret)
			{
				taxRate_a = tax_a.taxRate;
				taxRate_b = tax_b.taxRate;
				c = i;
				ret = curTax;
			}
		}
		return ret;
	}

	TaxData GetTaxOfA(float a)
	{
		if (a <= 36000)
			return TaxData(a * 0.03, 0.03);
		else if (a <= 144000)
			return TaxData(a * 0.1 - 2520, 0.1);
		else if (a < 300000)
			return TaxData(a * 0.2 - 16920, 0.2);
		else if (a < 420000)
			return TaxData(a * 0.25 - 31920, 0.25);
		else if (a < 660000)
			return TaxData(a * 0.3 - 52920, 0.3);
		else if (a < 9600000)
			return TaxData(a * 0.35 - 85920, 0.35);
		else
			return TaxData(a * 0.45 - 181920, 0.45);
	}

	TaxData GetTaxOfB(float a)
	{
		int temp = a / 12;
		if (a <= 3000)
			return TaxData(a * 0.03, 0.03);
		else if (a <= 12000)
			return TaxData(a * 0.1 - 210, 0.1);
		else if (a < 25000)
			return TaxData(a * 0.2 - 1410, 0.2);
		else if (a < 35000)
			return TaxData(a * 0.25 - 2660, 0.25);
		else if (a < 55000)
			return TaxData(a * 0.3 - 4410, 0.3);
		else if (a < 80000)
			return TaxData(a * 0.35 - 7160, 0.5);
		else
			return TaxData(a * 0.45 - 15160, 0.45);
	}

	void RunTest()
	{
		//读取数据得到一个项id以及a,b值的数组
		//对数组中的每一项执行RunTestCase
		//将结果写入到excel中{姓名，最小税值，taxRate_a,taxRate_b}
	}

	void RunTestCase(float a, float b)
	{
		//初始化c,taxRate_a,taxRate_b
		//运行calMinTax得到最小税值以及对应的c值和A和B的税率值taxRate_a、taxRate_b
		//存到数组里去
	}
};