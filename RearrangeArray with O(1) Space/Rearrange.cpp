/*
 * Created on Wed Oct 07 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void rearrange(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[arr[i] % arr.size()] += i * arr.size();
    }
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] /= arr.size();
    }
}

int main()
{

    vector<int> arr;
    arr = {2, 0, 1, 4, 5, 3};
    rearrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;

    arr = {3, 2, 1, 0};
    rearrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;

    arr = {2, 0, 1, 4, 5, 3};
    rearrange(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
    // 1 2 0 5 3 4
    // 3 2 1 0
    // 1 2 0 5 3 4
    return 0;
}