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
    adj[v].emplace_back(v);
}

int getLevel(vector<int> adj[], int node, int vertices)
{

    vector<bool> visited(vertices, false);

    queue<int> que;
    que.push(0);
    visited[0] = true;
    int level = 0;
    if (node == 0)
        return 0;

    que.push(-1);

    while (!que.empty())
    {

        /* code */

        int n = que.front();
        que.pop();
        // cout<<endl;
        // cout<<n<<" ->>";

        if (n == -1)
        {
            // cout<<"here"<<endl;
            ++level;
            if (!que.empty())
                que.push(-1);

            continue;
        }

        for (auto i : adj[n])
        {
            // cout<<i<<" ";

            if (i == node)
                return level + 1;
            if (visited[i] == false)
            {

                visited[i] = true;
                que.push(i);
            }
        }
    }

    return -1;
}

int main()
{

    int vertices = 8;

    vector<int> adj[vertices];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 2, 5);

    cout << getLevel(adj, 1, vertices) << endl;

    cout << getLevel(adj, 2, vertices) << endl;

    cout << getLevel(adj, 4, vertices) << endl;

    cout << getLevel(adj, 5, vertices) << endl;

    // 1
    // 1
    // 2
    // 2

    return 0;
}