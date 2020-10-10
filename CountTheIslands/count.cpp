/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

template <typename TwoD>
void DFS(vector<vector<int>> &arr, TwoD &visited, int i, int j, int row_size, int col_size)
{
    visited[i][j] = true;

    pair<int, int> neighbours[8] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int next_i, next_j;

    for (pair<int, int> neigh : neighbours)
    {

        next_i = i + neigh.first;
        next_j = j + neigh.second;

        if (next_i >= 0 && next_i < row_size && next_j >= 0 && next_j < col_size)
        {
            if (arr[next_i][next_j] && visited[next_i][next_j] == false)
            {
                DFS(arr, visited, next_i, next_j, row_size, col_size);
            }
        }
    }
}

int countIslands(vector<vector<int>> arr, int row_size, int col_size)
{

    int visisted[101][101] = {false};

    // int row_size=arr.size();
    // int col_size=arr[0].size();

    int result = 0;

    for (int i = 0; i < row_size; ++i)
    {

        for (int j = 0; j < col_size; ++j)
        {

            if (arr[i][j] == 1 && visisted[i][j] == false)
            {
                DFS(arr, visisted, i, j, row_size, col_size);
                ++result;
            }
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> arr;
    arr = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}};
    cout << countIslands(arr, arr.size(), arr[0].size()) << endl;
    arr = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}};
    cout << countIslands(arr, arr.size(), arr[0].size()) << endl;

    arr = {
        {1, 1, 0},
        {0, 0, 1},
        {1, 0, 1}

    };
    cout << countIslands(arr, arr.size(), arr[0].size()) << endl;
    // 5
    // 2
    // 2
    return 0;
}