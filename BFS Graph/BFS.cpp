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

void BFSUtil(vector<int> adj[], vector<bool> &visited, int vertex)
{

    visited[vertex] = true;
    queue<int> que;
    que.push(vertex);
    while (!que.empty())
    {
        /* code */
        int vert = que.front();
        cout << vert << " ";
        for (int i = 0; i < adj[vert].size(); ++i)
        {
            if (visited[adj[vert][i]] == false)
            {

                que.push(adj[vert][i]);
                visited[adj[vert][i]] = true;
            }
        }
        que.pop();
    }
}

void BFS(vector<int> adj[], int vertices)
{

    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            BFSUtil(adj, visited, i);
        }
    }
}

int main()
{

    int vertices = 5;

    vector<int> adj[vertices];

    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    BFS(adj, vertices);

    // 0 4 1 2 3

    return 0;
}