/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> adj[], int vertex, list<int> &s, bool visited[])
{

    visited[vertex] = true;

    for (auto i : adj[vertex])
    {
        if (visited[i] == false)
        {
            DFS(adj, i, s, visited);
        }
    }

    // s.push(vertex);
    s.emplace_front(vertex);
}

list<int> topologicalSort(vector<int> adj[], int vertices)
{

    list<int> stack;
    bool visited[vertices] = {false};

    for (int i = 0; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            DFS(adj, i, stack, visited);
        }
    }

    return stack;
}

int main()
{

    int vertices = 6;
    vector<int> adj[vertices];

    adj[5].emplace_back(0);
    adj[5].emplace_back(2);
    adj[2].emplace_back(3);
    adj[4].emplace_back(0);
    adj[4].emplace_back(1);
    adj[1].emplace_back(3);
    list<int> result;
    result = topologicalSort(adj, vertices);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
