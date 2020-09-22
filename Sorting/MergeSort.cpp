/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int size_of_left_array = mid - start + 1;
    int size_of_right_array = end - start;
    int left_array[size_of_left_array];
    int right_array[size_of_right_array];
    for (int i = 0; i < size_of_left_array; ++i)
    {
        left_array[i] = arr[i + start];
    }
    for (int i = 0; i < size_of_right_array; ++i)
    {
        right_array[i] = arr[i + mid + 1];
    }

    int ptr_left = 0;
    int ptr_right = 0;
    int ptr_merge = start;

    while (ptr_left < size_of_left_array && ptr_right < size_of_right_array)
    {
        /* code */

        if (left_array[ptr_left] > right_array[ptr_right])
        {
            arr[ptr_merge] = right_array[ptr_right];
            ++ptr_right;
        }
        else
        {
            arr[ptr_merge] = left_array[ptr_left];
            ++ptr_left;
        }
        ++ptr_merge;
    }

    while (ptr_left < size_of_left_array)
    {
        /* code */
        arr[ptr_merge] = left_array[ptr_left];
        ++ptr_merge;
        ++ptr_left;
    }

    while (ptr_right < size_of_right_array)
    {
        /* code */
        arr[ptr_merge] = right_array[ptr_right];
        ++ptr_merge;
        ++ptr_right;
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (end > start)
    {

        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{

    vector<int> arr{4, 5, 3, 6, 7, 9, 23, 56, 13, 89};
    mergeSort(arr, 0, arr.size() - 1);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}