#pragma once
#include "Contest_maxNumOfSubstrings.h"
#include "Contest_countSubTrees.h"
#include "Contest_204_1.h"
#include "Contest_204_2.h"
#include "Contest_204_4.h"
#include "Contest_au_1.h"
#include "Contest_au_2.h"
#include "Contest_au_3.h"
#include "Contest_206_2.h"
#include "Contest_213_1.h"
#include "Contest_213_2.h"
#include "Contest_213_3.h"
#include "Contest_213_4.h"

class contest
{
public:
	void RunTest()
	{
		//RunTest_204();
		//RunTest_Au();

		RunTest_213();
	}

	void RunTest_213()
	{
		//Contest_213_1 c1;
		//c1.RunTest();

		//Contest_213_2 c2;
		//c2.RunTest();

		/*Contest_213_3 c3;
		c3.RunTest();*/

		Contest_213_4 c4;
		c4.RunTest();
	}

	void RunTest_Au()
	{
		/*Contest_au_1 s;
		s.RunTest();*/

		//Contest_au_2 s;
		//s.RunTest();

		Contest_au_3 s;
		s.RunTest();
	}

	void RunTest_198()
	{
		//Contest_maxNumOfSubstrings s;

		Contest_countSubTrees s;
		s.RunTest();
	}

	//�����û�����ڶ��⣬�о���ţ�Ǽ��ˡ���һ��ʼ���ƺ��������ˣ����һ��Сʱ��ȥ�˻���ûAC��һֱ���Ǹ���ˮ��������������������ȥ�ģ���ʵӦ�������������ºú�˼��������Ȿ��������
	//��һ��������㷨�����޲���
	void RunTest_204()
	{
		//Contest_204_1 c1;
		//c1.RunTest();

		//Contest_204_2 c2;
		//c2.RunTest();


		//Contest_204_4 c4;
		//c4.RunTest();
	}

	void RunTest_206()
	{
		Contest_206_2 c3;
		c3.RunTest();
	}
};