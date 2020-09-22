/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int ptr1 = start - 1;
    int ptr2 = start;
    for (ptr2 = start; ptr2 < end; ++ptr2)
    {

        if (arr[ptr2] < pivot)
        {
            ++ptr1;
            swap(arr[ptr1], arr[ptr2]);
        }
    }

    ++ptr1;
    swap(arr[ptr1], arr[end]);
    return ptr1;
}

void quickSort(vector<int> &arr, int start, int end)
{

    if (end > start)
    {
        int paritionPoint = partition(arr, start, end);
        quickSort(arr, paritionPoint + 1, end);
        quickSort(arr, start, paritionPoint - 1);
    }
}

int main()
{

    vector<int> arr{45, 123, 56, 123, 1, 123, 56, 7, 2};

    quickSort(arr, 0, arr.size() - 1);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}