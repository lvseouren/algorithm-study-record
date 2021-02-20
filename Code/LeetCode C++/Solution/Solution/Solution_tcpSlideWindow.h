#pragma once
#include "SolutionBase.h"
class Solution_tcpSlideWindow :SolutionBase {
public:
	//窗口里只包含两种数据：
	//1.已发送未收到确认的
	//2.未发送但允许发送的
	void tcpSlideWindow()
	{
	
	}


	//收到确认，看情况右移滑窗
	void OnRecvAck()
	{

	}

	//将数据标记为已发送
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