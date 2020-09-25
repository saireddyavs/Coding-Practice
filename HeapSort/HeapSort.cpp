/*
 * Created on Fri Sep 25 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void heapDown(int arr[], int end, int index)
{

    int big_child = index;

    int parent = index;

    // 0 based indexing
    int left_child = parent * 2 + 1;
    int right_child = parent * 2 + 2;

    if (left_child < end && arr[left_child] > arr[parent])
    {
        big_child = left_child;
    }

    if (right_child < end && arr[right_child] > arr[big_child])
    {
        big_child = right_child;
    }

    if (big_child != index)
    {
        swap(arr[big_child], arr[index]);
        heapDown(arr, end, big_child);
    }
}

void heapSort(int arr[], int n)
{

    int array_size = n;

    int first_non_leaf = (array_size / 2) - 1;

    for (int i = first_non_leaf; i >= 0; --i)
    {
        heapDown(arr, array_size, i);
    }

    for (int i = array_size - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        heapDown(arr, i, 0);
    }
}

int main()
{

    int arr[] = {67, 89, 1, 45, 3, 8, 3, 12, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    for (int i : arr)
        cout << i << " ";
    return 0;
}