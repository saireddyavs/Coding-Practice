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

bool isCycleUtil(vector<int> adj[], int vertex, vector<bool> visited)
{
    // cout<<"before::"<<vertex<<endl;
    if (visited[vertex])
        return true;
    visited[vertex] = true;
    // cout<<"After:::"<<vertex<<endl;

    for (int i = 0; i < adj[vertex].size(); ++i)
    {

        bool res = isCycleUtil(adj, adj[vertex][i], visited);
        if (res)
            return true;
    }

    return false;
}

bool cycleinDirectedGraph(vector<int> adj[], int vertices)
{

    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i)
    {

        // cout<<"satrt::"<<i<<endl;
        bool res = isCycleUtil(adj, i, visited);

        if (res)
            return true;
    }

    return false;
}
int main()
{

    int vertices = 4;

    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << cycleinDirectedGraph(adj, 4) << endl;
    

    vector<int> adj1[vertices];

    addEdge(adj1, 0, 1);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 1, 2);
    // addEdge(adj1,2, 0);
    addEdge(adj1, 2, 3);
    // addEdge(adj1,3, 3);

    //  for (auto i : adj1)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    cout << cycleinDirectedGraph(adj1, 4) << endl;

    // 1
    // 0

    return 0;
}