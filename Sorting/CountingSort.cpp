/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int> &arr)
{

    vector<int> counts(*max_element(arr.begin(), arr.end()) + 1);

    for (auto i : arr)
        ++counts[i];

    for (int i = 1; i < counts.size(); ++i)
        counts[i] += counts[i - 1];

    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); ++i)
    {

        output[counts[arr[i]] - 1] = arr[i];
        --counts[arr[i]];
    }

    copy(output.begin(), output.end(), arr.begin());
}

int main()
{

    vector<int> arr{45, 34, 3, 12, 4, 2, 45, 2, 3, 45, 34};
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    countingSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}