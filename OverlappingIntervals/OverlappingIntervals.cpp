/*
 * Created on Wed Oct 07 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> overlappingIntervals(vector<pair<int, int>> arr)
{
    int start = 0;
    sort(arr.begin(), arr.end(), [](const pair<int, int> left, const pair<int, int> right) {
        return left.first < right.first;
    });

    // for(auto i:arr){
    //     cout<<" {"<<i.first<<","<<i.second<<"} ";

    // }

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[start].second >= arr[i].first)
        {
            arr[start].second = max(arr[start].second, arr[i].second);
        }
        else
        {
            ++start;
            arr[start] = arr[i];
        }
    }

    // cout<<start<<endl;

    return vector<pair<int, int>>(arr.begin(), arr.begin() + start + 1);
}

int main()
{

    vector<pair<int, int>> arr;

    vector<pair<int, int>> result;

    arr = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};

    result = overlappingIntervals(arr);

    for (auto i : result)
    {
        cout << " {" << i.first << "," << i.second << "} ";
    }
    cout << endl;

    arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

    result = overlappingIntervals(arr);

    for (auto i : result)
    {
        cout << " {" << i.first << "," << i.second << "} ";
    }
    cout << endl;

    arr = {{10, 11}, {12, 14}, {15, 16}, {17, 18}};

    result = overlappingIntervals(arr);

    for (auto i : result)
    {
        cout << " {" << i.first << "," << i.second << "} ";
    }
    cout << endl;

    arr = {{10, 11}, {11, 14}, {14, 18}, {18, 20}};

    result = overlappingIntervals(arr);

    for (auto i : result)
    {
        cout << " {" << i.first << "," << i.second << "} ";
    }
    cout << endl;

    //  {1,9}
    //  {1,4}  {6,8}  {9,10}
    //  {10,11}  {12,14}  {15,16}  {17,18}
    //  {10,20}

    return 0;
}