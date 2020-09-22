/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void buubleSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int single_swap_occured = false;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                single_swap_occured = true;
            }
        }
        if (!single_swap_occured)
            break;
    }
}

int main()
{

    vector<int> arr{5, 1, 4, 2, 8};
    buubleSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}