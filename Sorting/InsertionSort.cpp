/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr)
{

    int elem, j;

    for (int i = 1; i < arr.size(); ++i)
    {
        elem = arr[i];
        j = i - 1;
        while (arr[j] > elem && j >= 0)
        {
            /* code */
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = elem;
    }
}

int main()
{

    vector<int> arr{123, 67, 123, 2, 8, 12, 4, 6, 3, 5};
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    insertionSort(arr);
    for (auto i : arr)
        cout << i << " ";

    return 0;
}