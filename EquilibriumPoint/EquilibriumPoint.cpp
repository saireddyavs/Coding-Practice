/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int equilibriumPoint(vector<int> arr)
{
    int start = accumulate(arr.begin(), arr.end(), 0);

    int end = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        start -= arr[i];
        if (start == end)
        {
            return i;
        }
        end += arr[i];
    }

    return -1;
}

int main()
{

    cout << equilibriumPoint(vector<int>{1, 1, 3, 2}) << endl;

    cout << equilibriumPoint(vector<int>{10, 10, 20, 30, 40, 50}) << endl;

    // 2
    // -1

    return 0;
}