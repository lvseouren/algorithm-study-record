#pragma once
#include "SolutionBase.h"
class Solution_tcpSlideWindow :SolutionBase {
public:
	//������ֻ�����������ݣ�
	//1.�ѷ���δ�յ�ȷ�ϵ�
	//2.δ���͵������͵�
	void tcpSlideWindow()
	{
	
	}


	//�յ�ȷ�ϣ���������ƻ���
	//���裺�������յ�ȷ�ϵ���array_rev�����������±�Ϊleft
	void OnRecvAck()
	{
		int left;
		vector<int> array_rec;
		int comboIndex = left;
		for (int i = 0; i < array_rec.size(); ++i)
		{
			if (array_rec[i] == comboIndex)
			{
				comboIndex++;
			}
			else
				break;
		}
	}

	//�����ݱ��Ϊ�ѷ���
	void SendData()
	{

	}

	void RunTest()
	{
		RunTestCase();
	}

	void RunTestCase()
	{
		tcpSlideWindow();
	}
};