/*
 * Created on Tue Oct 06 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> miniumDistanceBetweenTwoNumbers(vector<int> arr, int num1, int num2)
{
    int found = -1;
    int diff = INT_MAX;
    pair<int, int> indexes;
    for (int i = 0; i < arr.size(); ++i)
    {

        if (arr[i] == num1 || arr[i] == num2)
        {
            if (found != -1 && arr[found] != arr[i])
            {
                // diff=min(diff,i-found);
                if (diff > i - found)
                {
                    diff = i - found;
                    indexes = {i, found};
                }
            }
            found = i;
        }
    }

    return {diff, indexes};
}

int main()
{

    pair<int, pair<int, int>> result;

    result = miniumDistanceBetweenTwoNumbers(vector<int>{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 1, 3, 4}, 1, 6);

    cout << result.first << "=" << result.second.first << "," << result.second.second << endl;

    result = miniumDistanceBetweenTwoNumbers(vector<int>{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 1, 3, 4}, 5, 3);
    cout << result.first << "=" << result.second.first << "," << result.second.second << endl;

    result = miniumDistanceBetweenTwoNumbers(vector<int>{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 1, 3, 4}, 4, 1);
    cout << result.first << "=" << result.second.first << "," << result.second.second << endl;

    // 1=6,5
    // 2=4,2
    // 2=11,9

    return 0;
}