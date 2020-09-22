
/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> smallestDifferenceinArrays(vector<int> arr1, vector<int> arr2)
{
    int size1 = arr1.size();
    int size2 = arr2.size();
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    pair<int, pair<int, int>> result;
    result.first = INT_MAX;
    result.second.first = 0;
    result.second.second = 0;
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < size1 && ptr2 < size2)
    {
        /* code */
        if (abs(arr1[ptr1] - arr2[ptr2]) < result.first)
        {
            result.first = abs(arr1[ptr1] - arr2[ptr2]);
            result.second.first = arr1[ptr1];
            result.second.second = arr2[ptr2];
        }

        if (arr1[ptr1] > arr2[ptr2])
        {
            ++ptr2;
        }
        else if (arr1[ptr1] < arr2[ptr2])
        {
            ++ptr1;
        }
        else
        {
            result.first = 0;
            result.second.first = arr1[ptr1];
            result.second.second = arr2[ptr2];
            break;
        }
    }

    return result;
}

int main()
{

    pair<int, pair<int, int>> result;

    result = smallestDifferenceinArrays(vector<int>{10, 20, 30, 40, 50, 60, 70}, vector<int>{29, 38, 47, 56, 65, 74});

    cout << result.first << ":" << result.second.first << "," << result.second.second << endl;

    result = smallestDifferenceinArrays(vector<int>{10, 20, 30, 40, 50, 60, 70}, vector<int>{29, 38, 47, 50, 65, 74});

    cout << result.first << ":" << result.second.first << "," << result.second.second << endl;

    result = smallestDifferenceinArrays(vector<int>{101, 201, 301, 401, 501, 601, 701}, vector<int>{29, 38, 47, 56, 65, 74});

    cout << result.first << ":" << result.second.first << "," << result.second.second << endl;
    result = smallestDifferenceinArrays(vector<int>{1, 2, 3, 4, 5, 6, 7}, vector<int>{29, 38, 47, 56, 65, 74});

    cout << result.first << ":" << result.second.first << "," << result.second.second << endl;

    return 0;
    // 1:30,29
    // 0:50,50
    // 27:101,74
    // 22:7,29
}