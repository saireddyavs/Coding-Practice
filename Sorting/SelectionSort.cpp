/*
 * Created on Tue Sep 22 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); ++i)
    {

        int min = i;

        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] <= arr[min])
            {
                min = j;
            }
        }

        swap(arr[min], arr[i]);
    }
}

int main()
{

    vector<int> arr{4, 5, 6, 3, 1, 78, 3, 45, 23};

    selectionSort(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}