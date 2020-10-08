/*
 * Created on Thu Oct 08 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int RainWater(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int result = 0;
    int left_max = 0;
    int right_max = 0;
    while (start <= end)
    {

        if (arr[start] < arr[end])
        {

            left_max = max(left_max, arr[start]);
            result += left_max - arr[start];
            ++start;
        }
        else
        {
            right_max = max(right_max, arr[end]);
            result += right_max - arr[end];
            --end;
        }
    }

    return result;
}

int main()
{

    cout << RainWater(vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;

    cout << RainWater(vector<int>{1, 0, 0, 0, 1}) << endl;

    cout << RainWater(vector<int>{1, 0, 0, 0, 0}) << endl;

    cout << RainWater(vector<int>{1, 0, 4, 0, 1}) << endl;
    // 6
    // 3
    // 0
    // 2
    return 0;
}