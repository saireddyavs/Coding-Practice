/*
 * Created on Fri Oct 09 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int rottenOranges(vector<vector<int>> &arr, int R, int C)
{

    pair<int, int> current;

    queue<pair<int, int>> que;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (arr[i][j] == 2)
                que.push({i, j});
        }
    }

    if (que.size() == 0)
        return -1;

    que.push({-1, -1});

    int result = 0;

    while (!que.empty())
    {
        /* code */

        current = que.front();
        que.pop();
        // cout<<current.first<<"::"<<current.second<<endl;
        if (current.first == -1)
        {

            ++result;

            if (!que.empty())
            {
                que.push({-1, -1});
            }

            continue;
        }

        if (current.first - 1 >= 0 && arr[current.first - 1][current.second] == 1)
        { //up

            que.push({current.first - 1, current.second});

            arr[current.first - 1][current.second] = 2;
        }

        if (current.first + 1 < R && arr[current.first + 1][current.second] == 1)
        {
            que.push({current.first + 1, current.second});
            arr[current.first + 1][current.second] = 2;
        }

        if (current.second - 1 >= 0 && arr[current.first][current.second - 1] == 1)
        {

            que.push({current.first, current.second - 1});

            arr[current.first][current.second - 1] = 2;
        }

        if (current.second + 1 < C && arr[current.first][current.second + 1] == 1)
        {

            que.push({current.first, current.second + 1});

            arr[current.first][current.second + 1] = 2;
        }

        // que.pop();
    }

    for (auto i : arr)
    {
        for (auto j : i)
            if (j == 1)
                return -1;
    }

    return result - 1;
}

int main()
{

    vector<vector<int>> arr;

    arr = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};

    cout << rottenOranges(arr, 3, 5) << endl;

    arr = {
        {2, 1, 0, 2, 1},
        {0, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};

    cout << rottenOranges(arr, 3, 5) << endl;

    return 0;
}