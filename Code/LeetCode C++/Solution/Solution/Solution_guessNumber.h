#pragma once
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#include <iostream>
using namespace std;
class Solution_guessNumber {
public:
    int desNum;
    int guessNumber(int n) 
    {
        int left = 0, right = n;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0)
                return mid;
            else if (result == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int guess(int num)
    {
        if (num == desNum)
            return 0;
        else if (num < desNum)
            return 1;
        else
            return -1;
    }

	void RunTest()
	{
		RunTestCase(10, 6);

	}

	void RunTestCase(int input, int des)
    {
        cout << "input:" << input << ",expect:" << des << endl;
        desNum = des;
        cout <<"output:"<< guessNumber(input) << endl;
	}
};