#pragma once
#include "SolutionBase.h"
#include "math.h"
#include <windows.h>

class temSolu
{
	vector<int> bookRecord;
public:
	temSolu(int cnt)
	{
		bookRecord = vector<int>(cnt,0);
	}

	int GetTotalExp(vector<int> bookExp)
	{
		int ret = 0;
		for (int i = 0; i < bookRecord.size(); i++)
		{
			ret += bookRecord.at(i)* bookExp[i];
		}
		if (ret == 0)
			return INT_MAX;
		else
			return ret;
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

	void Reset()
	{
		SetRecord({ 0,0,0,0 });
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
		{
			vector<int> ret(bookExp.size(), 0);
			for(int i = 0;i<bookExp.size();++i)
				if (bookCnt[i] > 0)
				{
					ret[i] = 1;
					return ret;
				}
		}

		desExp = ceil(desExp*1.0/bookExp[0]);
	
		for (int i = bookExp.size()-1; i>=0; --i)
		{
			bookExp[i] /= bookExp[0];
		}
	
		vector<temSolu> dp(desExp+1, temSolu(bookExp.size()));
		for (int i = bookExp[0]; i <= desExp; ++i)
		{
			for (int j = bookExp.size()-1; j >= 0; --j)
			{
				int curExp = bookExp[j];
				int preExp = i - curExp;
				int curDpIndex = i;
				if (preExp>=0)
				{
					if (dp[preExp].GetTotalExp(bookExp) + curExp < dp[curDpIndex].GetTotalExp(bookExp) && bookCnt[j]>dp[preExp].GetRecord(j))
					{
						dp[curDpIndex].SetRecord(dp[preExp].GetBookRecord());
						dp[curDpIndex].SetRecord(j, dp[preExp].GetRecord(j) + 1);
					}
				}
				else
				{
					if (bookCnt[j] > 0)
					{
						dp[curDpIndex].SetRecord({ 0,0,0,0 });
						dp[curDpIndex].SetRecord(j, 1);
					}
				}
			}
		}

		return dp[desExp].GetBookRecord();
	}

	vector<int> bestSoluToReachSpecValue_greedy(int desExp, vector<int> bookExp, vector<int> bookCnt)
	{
		int curExp = 0;
		vector<int> ret(bookCnt.size(), 0);
		while (true)
		{
			bool added = false;
			for (int i = bookExp.size()-1; i >= 0; --i)
			{
				if (bookCnt[i]>0 && curExp + bookExp[i] < desExp)
				{
					added = true;
					curExp += bookExp[i];
					bookCnt[i]--;
					ret[i]++;
					break;
				}
			}
			if (!added)
				break;
		}
		vector<int> tobeAdd = bestSoluToReachSpecValue(desExp - curExp, bookExp, bookCnt);
		for (int i = 0; i < ret.size(); ++i)
			ret[i] += tobeAdd[i];
		return ret;
	}

	void RunTest()
	{
		RunTestCase(10000000, { 100,200,500,1000,1500,2000,5000,10000 }, {100000,100009,200,0,10,20,30,40});
		RunTestCase(1000000, { 100,200,500,1000 }, { 100000,100009,100001,0 });
		RunTestCase(100000, { 100,200,500,1000 }, { 100000,100009,100001,0 });
		RunTestCase(10000, { 100,200,500,1000 }, { 100000,100009,100001,0 });


		RunTestCase(5000, { 100,200,500,1000 }, { 15,15,3,4 });
		RunTestCase(1000, { 100,200,500,1000 }, { 15,15,1,0 });
		RunTestCase(150, { 100,200,500,1000 }, { 15,15,3,5 });
		RunTestCase(50, { 100,200,500,1000 }, { 0,15,3,5 });
	}

	void RunTestCase(int desExp, vector<int> bookExp, vector<int> bookCnt)
	{
		DWORD startTime = GetTickCount();

		cout << "开始时间：" << startTime << endl;
		cout << "目标经验值：" << desExp << endl;
		cout << "技能书经验值集合：";
		vecPrinter->print(bookExp);
		cout << "玩家拥有的技能书数量：";
		vecPrinter->print(bookCnt);

		auto output = bestSoluToReachSpecValue_greedy(desExp, bookExp, bookCnt);
		cout << "最优方案：";
		vecPrinter->print(output);
		DWORD stopTime = GetTickCount();
		cout << "结束时间：" << stopTime<<endl;
		cout << "共计耗时：" << stopTime - startTime << "毫秒" << endl;
		cout << endl;
	}
};