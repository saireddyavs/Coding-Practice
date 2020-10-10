/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> neighbours[] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}};

template <typename TwoD>
void DFS(vector<vector<int>> &arr, TwoD &visited, int i, int j, int &present_count)
{

    visited[i][j] = true;

    int next_i, next_j;

    for (auto neigh : neighbours)
    {
        next_i = neigh.first + i;
        next_j = neigh.second + j;

        if (next_i >= 0 && next_i < arr.size() && next_j >= 0 && next_j < arr[next_i].size())
        {
            if (visited[next_i][next_j] == false && arr[next_i][next_j] == 1)
            {
                visited[next_i][next_j] = true;
                ++present_count;
                DFS(arr, visited, next_i, next_j, present_count);
            }
        }
    }
}

int largetRegion(vector<vector<int>> &arr)
{

    bool visited[50][50] = {false};

    int result = INT_MIN;

    int present_count;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {

            present_count = 1;

            // cout<<i<<"::"<<j<<"===="<<arr[i][j]<<endl;

            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                // cout<<i<<"---"<<j<<endl;
                DFS(arr, visited, i, j, present_count);
                result = max(result, present_count);
            }
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> arr;
    arr = vector<vector<int>>{
        {1, 1, 0},
        {0, 0, 1},
        {1, 0, 1}};

    cout << largetRegion(arr) << endl;

    arr = {{1}, {1}, {1}};
    cout << largetRegion(arr) << endl;

    arr = {
        {1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1},
        {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0}};
    cout << largetRegion(arr) << endl;
    arr = {
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}};
    cout << largetRegion(arr) << endl;

    // 4
    // 3
    // 8
    // 11
    return 0;
}