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

void DFSUtil(vector<int> adj[], vector<bool> &visited, int vertex)
{

    visited[vertex] = true;

    for (auto i : adj[vertex])
    {

        if (visited[i] == false)
        {
            DFSUtil(adj, visited, i);
        }
    }
}

int mothervertex(vector<int> adj[], int vertices)
{

    vector<bool> visited(vertices, false);

    int last_visited = -1;

    for (int i = 0; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            DFSUtil(adj, visited, i);
            last_visited = i;
        }
    }

    fill(visited.begin(), visited.end(), false);

    DFSUtil(adj, visited, last_visited);

    for (auto i : visited)
    {
        if (i == false)
            return -1;
    }

    return last_visited;
}
int main()
{

    int vertices;

    vertices = 5;

    vector<int> adj[vertices];

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    cout << mothervertex(adj, vertices) << endl;

    vertices = 7;

    vector<int> adj1[vertices];

    addEdge(adj1, 0, 1);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 4, 1);
    addEdge(adj1, 6, 4);
    addEdge(adj1, 5, 6);
    addEdge(adj1, 5, 2);
    addEdge(adj1, 6, 0);
    cout << mothervertex(adj1, vertices);

    // 0
    // 5
    return 0;
}