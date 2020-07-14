#pragma once
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> data;
	stack<int> minStack;

	MinStack() {
		minStack.push(INT_MAX);
	}

	void push(int x) {
		data.push(x);
		minStack.push(min(minStack.top(), x));
	}

	void pop() {
		data.pop();
		minStack.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minStack.top();
	}
};