/*
 * Created on Fri Oct 09 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int minswaps(vector<int> arr)
{
    int result = 0;

    int min_index = -1;

    int min_element = -1;
    for (int i = 0; i < arr.size() - 1; ++i)
    {

        min_element = arr[i];
        min_index = i;

        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] < min_element)
            {
                min_element = arr[j];
                min_index = j;
            }
        }

        if (min_index != i)
        {
            // cout<<arr[min_index]<<" ::"<<arr[i]<<endl;
            swap(arr[min_index], arr[i]);
            ++result;
        }
    }

    return result;
}
int main()
{

    cout << minswaps(vector<int>{1, 5, 4, 3, 2}) << endl;
    cout << minswaps(vector<int>{3, 5, 2, 4, 6, 8}) << endl;

    // 2
    // 3
    return 0;
}