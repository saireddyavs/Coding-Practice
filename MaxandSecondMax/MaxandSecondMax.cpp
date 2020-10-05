/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> maxandSecondMax(vector<int> arr)
{
    int first = INT_MIN, second = INT_MIN;
    if (arr.size() == 0)
        return {first, second};
    if (arr.size() == 1)
        return {arr[0], second};

    first = arr[0];

    for (int i = 01; i < arr.size(); ++i)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
            continue;
        }

        if (arr[i] < first && arr[i] > second)
        {
            second = arr[i];
        }
    }

    return {first, second};
}

int main()
{

    pair<int, int> result;

    result = maxandSecondMax(vector<int>{1, 2, 3, 4, 1, 2, 3, 6, 7, 8, 1});
    cout << result.first << " : " << result.second << endl;

    result = maxandSecondMax(vector<int>{});
    cout << result.first << " : " << result.second << endl;

    result = maxandSecondMax(vector<int>{1});
    cout << result.first << " : " << result.second << endl;

    result = maxandSecondMax(vector<int>{1, 2, 3, 4, 12, 4, 81});
    cout << result.first << " : " << result.second << endl;

    result = maxandSecondMax(vector<int>{1, 1});
    cout << result.first << " : " << result.second << endl;

    // 8 : 7
    // -2147483648 : -2147483648
    // 1 : -2147483648
    // 81 : 12
    // 1 : -2147483648
    return 0;
}