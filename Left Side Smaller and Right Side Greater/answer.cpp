/*
 * Created on Mon Dec 20 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

int leftSideSmallerAndRightSideGreter(vector<int> arr)
{
    int size = arr.size();

    int left[size];

    fill(left, left + size, INT_MAX);

    for (int i = 1;i < size;++i) {
        left[i] = min(left[i - 1], arr[i - 1]);
    }

    int right_max = arr[size - 1];

    for (int i = size - 2;i >= 1;--i) {
        // cout << arr[i] << " " << left[i] << " " << right_max << endl;
        if (arr[i] > left[i] && arr[i] < right_max) {
            return i;
        };

        right_max = max(right_max, arr[i + 1]);
    }

    return -1;

}
int main() {

    vector<int> arr = { 1 };

    cout << leftSideSmallerAndRightSideGreter(arr) << endl;

    arr = { 1,2 };

    cout << leftSideSmallerAndRightSideGreter(arr) << endl;

    arr = { 1,2,3 };

    cout << leftSideSmallerAndRightSideGreter(arr) << endl;

    arr = { 1,3,4,2,6,8,9,7 };

    cout << leftSideSmallerAndRightSideGreter(arr) << endl;

    return 0;

}