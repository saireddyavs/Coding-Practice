/*
 * Created on Tue Oct 06 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> maximumIndex(vector<int> arr)
{
    vector<int> maximum_from_right(arr.begin(), arr.end());
    vector<int> minimum_from_left(arr.begin(), arr.end());

    for (int i = arr.size() - 2; i >= 0; --i)
    {
        maximum_from_right[i] = max(maximum_from_right[i], maximum_from_right[i + 1]);
    }
    for (int i = 1; i < arr.size(); ++i)
    {
        minimum_from_left[i] = min(minimum_from_left[i], minimum_from_left[i - 1]);
    }

    int start1 = 0;
    int start2 = 0;
    int result = INT_MIN;
    pair<int, int> elements = {0, 0};

    //     for(auto i:minimum_from_left)cout<<i<<" ";
    //     cout<<endl;
    //     for(auto i:maximum_from_right)cout<<i<<" ";
    // cout<<endl;
    while (start1 < arr.size() && start2 < arr.size())
    {
        if (maximum_from_right[start1] > minimum_from_left[start2])
        {
            // result=max(result,start1-start2);

            if (result < start1 - start2)
            {
                result = start1 - start2;
                elements = {start2, start1};
            }
            ++start1;
        }
        else
        {
            ++start2;
        }
    }

    return {result, elements};
}

int main()
{
    pair<int, pair<int, int>> result;
    result = maximumIndex(vector<int>{34, 8, 10, 3, 2, 80, 30, 33, 1});

    cout << result.first << "=" << result.second.second << "-" << result.second.first << endl;

    result = maximumIndex(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    cout << result.first << "=" << result.second.second << "-" << result.second.first << endl;
    // 6=7-1
    // 9=9-0

    return 0;
}