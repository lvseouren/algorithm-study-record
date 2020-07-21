#pragma once
#include <stack>
using namespace std;
class MyQueue {
public:
	stack<int> frontData;
	stack<int> backData;
	stack<int>* tempData;
	stack<int>* realData;

	/** Initialize your data structure here. */
	MyQueue() {
		tempData = &frontData;
		realData = &backData;
	}

	void switchBuffer()
	{
		stack<int>* temp = tempData;
		tempData = realData;
		realData = temp;
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		switchBuffer();
		while(!tempData->empty())
		{
			realData->push(tempData->top());
			tempData->pop();
		}
		realData->push(x);
		switchBuffer();
		while (!tempData->empty())
		{
			realData->push(tempData->top());
			tempData->pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ret = peek();
		realData->pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		return realData->top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return realData->empty();
	}
};