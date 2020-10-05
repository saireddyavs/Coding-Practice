/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int containerWithMostWater(vector<int> arr)
{

    int start = 0;
    int end = arr.size() - 1;
    int result = INT_MIN;
    while (start < end)
    {
        /* code */

        result = max(result, min(arr[start], arr[end]) * (end - start));

        // ++start;
        // --end;

        if (arr[start] > arr[end])
            --end;
        else
        {
            ++start;
        }

        // cout<<start<<"::"<<end<<endl;
    }

    return result;
}

int main()
{

    vector<int> arr;
    int result;

    arr = {7, 6, 1, 2, 3, 4, 5};

    result = containerWithMostWater(arr);
    cout << result << endl;

    arr = {12, 3, 1, 7, 4, 5, 20};

    result = containerWithMostWater(arr);
    cout << result << endl;

    arr = {1, 50, 40, 3};

    result = containerWithMostWater(arr);
    cout << result << endl;

    //     30
    // 72
    // 40

    return 0;
}