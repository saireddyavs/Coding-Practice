
/*
 * Created on Mon Oct 12 2020
 *
 * Copyright (c) 2020 SaiReddy
 */
// https://www.geeksforgeeks.org/kth-smallest-element-from-an-array-of-intervals/
// Given an array of intervals arr[] of size N, the task is to find the Kth smallest element among all the elements within the intervals of the given array.

#include <bits/stdc++.h>

using namespace std;

int kthSmallestfromArrayofIntervals(vector<pair<int, int>> &arr, int k)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i : arr)
    {
        pq.push(i);
    }

    int start = 0;
    pair<int, int> next;

    while (start < k && !pq.empty())
    {
        /* code */

        next = pq.top();
        pq.pop();

        if (next.first < next.second)
        {
            pq.push({next.first + 1, next.second});
        }

        ++start;
    }

    if (pq.empty())
        return -1;

    next = pq.top();

    return next.first;
}

int main()
{

    vector<pair<int, int>> arr;

    arr = {
        {5, 11},
        {10, 15},
        {12, 20}};

    cout << kthSmallestfromArrayofIntervals(arr, 12) << endl;

    cout << kthSmallestfromArrayofIntervals(arr, 12000) << endl;

    //   13
    // -1
    //
    return 0;
}