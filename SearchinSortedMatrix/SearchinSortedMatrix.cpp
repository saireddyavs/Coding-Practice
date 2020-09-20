/*
 * Created on Sun Sep 20 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> searchinSortedMatrix(vector<vector<int>> arr, int number)
{

    int start = 0;
    int end = arr[0].size() - 1;

    while (start < arr.size() && end >= 0)
    {
        if (arr[start][end] > number)
        {
            --end;
        }
        else if (arr[start][end] < number)
        {
            ++start;
        }
        else
        {
            return make_pair(start, end);
        }
    }

    return make_pair(-1, -1);
}

int main()
{

    vector<vector<int>> arr{
        vector<int>{1, 2, 3, 7, 15},
        vector<int>{4, 8, 11, 12, 16},
        vector<int>{5, 9, 14, 19, 21},
        vector<int>{6, 10, 17, 20, 22},

    };

    pair<int, int> result;
    result = searchinSortedMatrix(arr, 1);

    cout << result.first << ":" << result.second << endl;
    result = searchinSortedMatrix(arr, 10);

    cout << result.first << ":" << result.second << endl;
    result = searchinSortedMatrix(arr, 100);

    cout << result.first << ":" << result.second << endl;
    result = searchinSortedMatrix(arr, 14);

    cout << result.first << ":" << result.second << endl;
    result = searchinSortedMatrix(arr, 5);

    cout << result.first << ":" << result.second << endl;

    // 0:0
    // 3:1
    // -1:-1
    // 2:2
    // 2:0

    return 0;
}