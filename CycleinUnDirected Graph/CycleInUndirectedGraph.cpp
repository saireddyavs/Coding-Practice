
/*
 * Created on Fri Oct 09 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

bool cycleUtil(vector<int> adj[], int vertices, int vertex, vector<bool> &visited)
{

    queue<int> que;

    vector<int> parent(vertices, -1);

    que.push(vertex);

    visited[vertex] = true;

    while (!que.empty())
    {
        /* code */

        int u = que.front();
        que.pop();

        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                parent[v] = u;
                que.push(v);
            }
            else
            {
                if (parent[u] != v)
                    return true;
            }
        }
    }

    return false;
}

bool cycleinUndirectedGraph(vector<int> adj[], int vertices)
{
    vector<bool> visited(vertices, false);
    for (int i = 0; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            bool res = cycleUtil(adj, vertices, i, visited);
            if (res)
                return true;
        }
    }
    return false;
}

int main()
{

    int vertices = 4;
    vector<int> adj[vertices];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    cout << cycleinUndirectedGraph(adj, vertices) << endl;
    vector<int> adj1[vertices];
    addEdge(adj1, 0, 1);
    addEdge(adj1, 1, 2);
    // addEdge(adj1, 2, 0);
    addEdge(adj1, 2, 3);

    cout << cycleinUndirectedGraph(adj1, vertices) << endl;
    // 1
    // 0
}