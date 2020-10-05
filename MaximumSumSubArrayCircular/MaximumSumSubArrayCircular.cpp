/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int maximumSumSubArrayCircular(vector<int> arr)
{
    int max_present = arr[0], max_sofar = arr[0];
    int min_present = arr[0], min_sofar = arr[0];

    int total = arr[0], ele;

    for (int i = 1; i < arr.size(); ++i)
    {
        ele = arr[i];
        total += ele;
        max_present = max(max_present + ele, ele);
        max_sofar = max(max_sofar, max_present);
        min_present = min(ele, min_present + ele);
        min_sofar = min(min_sofar, min_present);
    }

    // if total==min_sofar means all are negative elements
    // if not above case we may are may not get max by considering cycle

    return total == min_sofar ? max_sofar : max(max_sofar, total - min_sofar);
}

int main()
{

    cout << maximumSumSubArrayCircular(vector<int>{8, -8, 9, -9, 10, -11, 12}) << endl;
    cout << maximumSumSubArrayCircular(vector<int>{-8, -8, -9, -7, -10, -11, -12}) << endl;
    cout << maximumSumSubArrayCircular(vector<int>{10, -3, -4, 7, 6, 5, -4, -1}) << endl;
    cout << maximumSumSubArrayCircular(vector<int>{-1, 40, -14, 7, 6, 5, -4, -1}) << endl;
    // 22
    // -7
    // 23
    // 52
}