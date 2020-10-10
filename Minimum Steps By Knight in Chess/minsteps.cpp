/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int minSteps(pair<int, int> source, pair<int, int> destination, int vertices)
{
    if (source == destination)
        return 0;
    bool visited[vertices][vertices] = {false};
    source.first -= 1;
    source.second -= 1;

    destination.first -= 1;
    destination.second -= 1;

    queue<pair<int, int>> que;
    que.push(source);
    que.push({-1, -1});

    pair<int, int> possible_moves[] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    pair<int, int> next;

    int length = 1; //atleast one step

    pair<int, int> move;

    visited[source.first][source.second] = true;

    while (!que.empty())
    {
        /* code */

        next = que.front();
        que.pop();

        if (next.first == -1)
        {

            // cout<<"hi"<<endl;

            ++length;
            if (!que.empty())
            {
                que.push({-1, -1});
            }
            continue;
        }

        for (auto possible : possible_moves)
        {

            move.first = possible.first + next.first;
            move.second = possible.second + next.second;

            if (move.first >= 0 && move.first < vertices && move.second >= 0 && move.second < vertices)
            {

                if (move.first == destination.first && move.second == destination.second)
                {
                    return length;
                }
                if (visited[move.first][move.second] == false)
                {
                    que.push(move);
                    visited[move.first][move.second] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{

    cout << minSteps({1, 1}, {30, 30}, 30) << endl;

    cout << minSteps({4, 5}, {1, 1}, 6) << endl;

    cout << minSteps({5, 7}, {15, 20}, 20) << endl;

    // 20
    // 3
    // 9
    return 0;
}