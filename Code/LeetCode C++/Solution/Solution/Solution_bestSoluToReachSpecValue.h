#pragma once
#include "SolutionBase.h"
#include "math.h"
class temSolu
{
	vector<int> bookRecord;
public:
	temSolu()
	{
		bookRecord = vector<int>(4.0);
	}

	int GetTotalExp(vector<int> bookExp)
	{
		int ret = 0;
		for (int i = 0; i < bookRecord.size(); i++)
		{
			ret += bookRecord.at(i)* bookExp[i];
		}
		if (ret > 0)
			return ret;
		else
			return INT_MAX;
	}

	void SetRecord(vector<int> record)
	{
		for (int i = 0; i < record.size(); ++i)
			bookRecord[i] = record[i];
	}

	void SetRecord(int index, int cnt)
	{
		bookRecord.at(index) = cnt;
	}

	int GetRecord(int index)
	{
		return bookRecord.at(index);
	}

	vector<int> GetBookRecord()
	{
		return bookRecord;
	}
};

class Solution_bestSoluToReachSpecValue :SolutionBase {
public:

	//bookExp:技能书经验值取值集合
	//bookCnt:对应技能书拥有的数量
	//desExp:目标值
	//目标：对所有的i进行以下求和 ret[i]*bookExp[i]，使得和值>=desExp且最小
	vector<int> bestSoluToReachSpecValue(int desExp, vector<int> bookExp,vector<int> bookCnt)
	{
		if (desExp < bookExp[0])
			return { 1,0,0,0 };

		desExp = ceil(desExp*1.0/bookExp[0]);
	
		for (int i = bookExp.size()-1; i>=0; --i)
		{
			bookExp[i] /= bookExp[0];
		}
		vector<temSolu> dp(desExp+1);
		for (int i = bookExp[0]; i <= desExp; ++i)
		{
			for (int j = bookExp.size()-1; j >= 0; --j)
			{
				int curExp = bookExp[j];
				int preExp = i - curExp;
				if (preExp >= 0)
				{
					if (dp[preExp].GetTotalExp(bookExp) + curExp < dp[i].GetTotalExp(bookExp) && bookCnt[j]>dp[preExp].GetRecord(j))
					{
						dp[i].SetRecord(dp[preExp].GetBookRecord());
						dp[i].SetRecord(j, dp[preExp].GetRecord(j) + 1);
					}
				}
				else
				{
					if (bookCnt[j] > 0)
					{
						dp[i].SetRecord({ 0,0,0,0 });
						dp[i].SetRecord(j, 1);
					}
				}
			}
		}

		return dp[desExp].GetBookRecord();
	}

	void RunTest()
	{
		RunTestCase(2300, { 100,200,500,1000 }, {0,9,1,0});
		//RunTestCase(1500, { 100,200,500,1000 }, { 1,2,3,0 });
		//RunTestCase(1500, { 100,200,500,1000 }, { 15,15,3,0 });

		RunTestCase(5000, { 100,200,500,1000 }, { 15,15,3,4 });
		RunTestCase(1000, { 100,200,500,1000 }, { 15,15,1,0 });
		RunTestCase(150, { 100,200,500,1000 }, { 15,15,3,5 });
		RunTestCase(50, { 100,200,500,1000 }, { 15,15,3,5 });
	}

	void RunTestCase(int desExp, vector<int> bookExp, vector<int> bookCnt)
	{
		cout << "目标经验值：" << desExp << endl;
		cout << "技能书经验值集合：";
		vecPrinter->print(bookExp);
		cout << "玩家拥有的技能书数量：";
		vecPrinter->print(bookCnt);

		auto output = bestSoluToReachSpecValue(desExp, bookExp, bookCnt);
		cout << "最优方案：";
		vecPrinter->print(output);
		cout << endl;
	}
};