/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void duplicatesinArray(vector<int> arr)
{

    int size = arr.size();

    for (int i = 0; i < size; ++i)
    {
        arr[arr[i] % size] += size; // %size beacause if we have >2 3rd time arr[arr[i]] inner arr[i] will be more than n-1
    }

    for (int i = 0; i < size; ++i)
    {
        if ((arr[i] / size) > 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{

    duplicatesinArray(vector<int>{1, 2, 3, 4, 1, 6, 7, 8, 1, 2, 3});

    return 0;
}