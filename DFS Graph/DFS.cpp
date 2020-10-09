/*
 * Created on Fri Oct 09 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int source, int destination)
{
    adj[source].emplace_back(destination);
}

void DFSUtil(vector<int> adj[], int vertex, vector<bool> &visited)
{

    visited[vertex] = true;

    cout << vertex << " ";

    for (int i = 0; i < adj[vertex].size(); ++i)
    {
        // cout<<vertex<<"::"<<adj[vertex][i]<<endl;
        if (visited[adj[vertex][i]] == false)
        {
            DFSUtil(adj, adj[vertex][i], visited);
        }
    }
}

void DFS(vector<int> adj[], int vertices)
{
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            DFSUtil(adj, i, visited);
        }
    }
}

int main()
{
    int vertices = 5;
    vector<int> adj[vertices];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    for (auto i : adj)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    DFS(adj, vertices);

    // 0 2 3 4 1
    return 0;
}
