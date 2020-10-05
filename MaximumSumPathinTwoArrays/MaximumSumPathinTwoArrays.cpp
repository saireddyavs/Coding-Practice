/*
 * Created on Mon Oct 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int maximumSumPathinTwoArrays(vector<int> arr1, vector<int> arr2)
{

    int result = 0;

    int sum_in_arr1 = 0;
    int sum_in_arr2 = 0;

    int start_arr1 = 0, end_arr1 = arr1.size();
    int start_arr2 = 0, end_arr2 = arr2.size();

    while (start_arr1 < end_arr1 && start_arr2 < end_arr2)
    {
        if (arr1[start_arr1] < arr2[start_arr2])
        {
            sum_in_arr1 += arr1[start_arr1];
            ++start_arr1;
        }
        else if (arr2[start_arr2] < arr1[start_arr1])
        {
            sum_in_arr2 += arr2[start_arr2];
            ++start_arr2;
        }
        else
        {
            result += max(sum_in_arr1, sum_in_arr2);
            result += arr1[start_arr1];
            ++start_arr1;
            ++start_arr2;

            sum_in_arr1 = 0;
            sum_in_arr2 = 0;
        }
    }

    //  cout<<result<<":"<<start_arr1<<":"<<start_arr2<<endl;
    while (start_arr1 < end_arr1)
    {
        sum_in_arr1 += arr1[start_arr1];
        ++start_arr1;
    }

    while (start_arr2 < end_arr2)
    {
        sum_in_arr2 += arr2[start_arr2];
        ++start_arr2;
    }

    result += max(sum_in_arr1, sum_in_arr2);

    return result;
}

int main()
{

    cout << maximumSumPathinTwoArrays(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, vector<int>{3, 4, 5, 6, 7, 8, 9, 12, 12, 10}) << endl;
    cout << maximumSumPathinTwoArrays(vector<int>{2, 3, 7, 10, 12}, vector<int>{1, 5, 7, 8}) << endl;
    cout << maximumSumPathinTwoArrays(vector<int>{1, 4, 5}, vector<int>{1, 4, 7}) << endl;
    // 79
    // 35
    // 12
    return 0;
}