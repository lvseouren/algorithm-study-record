#pragma once
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution_evalRPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i = 0;i<tokens.size();i++)
        {
            if (isOp(tokens[i]))
            {
                int num2 = num.top();
                num.pop();
                int num1 = num.top();
                num.pop();
                num.push(op(tokens[i], num1, num2));
            }
            else
            {
                num.push(stoi(tokens[i]));
            }
        }
        return num.top();
    }

    bool isOp(string c)
    {
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }

    int op(string op, int num1, int num2)
    {
        if (op == "+")
            return num1 + num2;
        else if (op == "-")
            return num1 - num2;
        else if (op == "*")
            return num1 * num2;
        else
            return num1 / num2;
    }
};