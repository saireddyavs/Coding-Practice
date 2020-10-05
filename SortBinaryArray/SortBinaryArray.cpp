/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void sortBinaryArray(vector<int> &arr)
{

    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {

        if (arr[start] == 0)
        {

            ++start;
            continue;
        }
        if (arr[end] == 1)
        {
            --end;
            continue;
        }

        swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main()
{

    vector<int> arr;

    arr = {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0};

    sortBinaryArray(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    sortBinaryArray(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    sortBinaryArray(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    // 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
    // 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
    // 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1

    return 0;
}