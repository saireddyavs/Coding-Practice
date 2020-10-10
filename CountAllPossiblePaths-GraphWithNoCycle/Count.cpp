/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int source, int destination)
{
    adj[source].emplace_back(destination);
}

int countPaths(vector<int> adj[], int source, int destination, int vertices)
{

    int possible_count = 0;

    queue<int> que;
    que.push(source);

    while (!que.empty())
    {
        int vertex = que.front();
        que.pop();

        for (auto i : adj[vertex])
        {
            if (i == destination)
                possible_count++;
            que.push(i);
        }
    }

    return possible_count;
}

int main()
{

    int vertices = 5;

    vector<int> adj[vertices + 1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 3);

    cout << countPaths(adj, 1, 5, vertices) << endl;

    vector<int> adj1[vertices];

    addEdge(adj1, 0, 1);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 1, 4);
    addEdge(adj1, 2, 4);

    cout << countPaths(adj1, 0, 3, vertices) << endl;

    // 4
    // 3

    return 0;
}