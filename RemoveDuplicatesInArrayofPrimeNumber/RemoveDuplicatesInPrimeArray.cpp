/*
 * Created on Wed Oct 07 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> removeDuplicatesInArrayOfPrimes(vector<int> arr)
{
    int start = 0;
    int product = 1;
    for (auto i : arr)
    {

        if (product % i != 0)
        {

            arr[start] = i;
            ++start;
            product *= i;
        }
    }

    return vector<int>(arr.begin(), arr.begin() + start);
}

int main()
{

    vector<int> arr;
    vector<int> result;

    arr = {2, 3, 5, 2, 3, 7, 11, 2, 13};

    result = removeDuplicatesInArrayOfPrimes(arr);
    for (auto i : result)
        cout << i << " ";
    cout << endl;

    arr = {2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3};

    result = removeDuplicatesInArrayOfPrimes(arr);
    for (auto i : result)
        cout << i << " ";
    cout << endl;

    arr = {5, 5, 5, 5, 5, 5, 5, 5, 5};

    result = removeDuplicatesInArrayOfPrimes(arr);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    // 2 3 5 7 11 13
    // 2 3
    // 5
    return 0;
}