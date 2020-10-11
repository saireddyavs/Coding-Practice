/*
 * Created on Sun Oct 11 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

// struct edge{
//     int source,destination,weight;
//     edge(int u,int v,int w) : source(u),destination(v),weight(w){}
// };

void addEdge(vector<pair<int, int>> adj[], int u, int v, int cost)
{
    adj[u].emplace_back(make_pair(v, cost));
    adj[v].emplace_back(make_pair(u, cost));
}

void prims(vector<pair<int, int>> adj[], int source, int vertices, int edges)
{

    int required_edges = vertices - 1;

    if (required_edges > edges)
        return;

    bool visited[vertices] = {false};

    int min_path_weights[vertices];

    fill(min_path_weights, min_path_weights + vertices, INT_MAX);

    int parent[vertices] = {-1};

    // for(auto i:parent)cout<<i<<" ";

    fill(parent, parent + vertices, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({source, 0});

    int cost = 0;

    while (!pq.empty())
    {
        /* code */
        pair<int, int> next = pq.top();
        pq.pop();

        if (visited[next.second])
            continue;

        visited[next.second] = true;

        cost += next.first;

        for (auto i : adj[next.second])
        {
            if (visited[i.first] == false)
            {
                // cout<<i.second<<"::"<<min_path_weights[i.first]<<"::herre::"<<i.first<<endl;

                if (min_path_weights[i.first] > i.second)
                {
                    //    cout<<"herre::"<<i.first<<endl;
                    min_path_weights[i.first] = i.second;
                    pq.push({i.second, i.first});
                    parent[i.first] = next.second;
                }
            }
        }
    }

    for (int i = 0; i < vertices; ++i)
    {
        cout << parent[i] << "--->" << i << endl;
    }
    cout << cost << endl;
}

int main()
{

    int vertices = 9;
    vector<pair<int, int>> adj[vertices];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    prims(adj, 0, vertices, 14);

    // -1--->0
    // 0--->1
    // 1--->2
    // 2--->3
    // 3--->4
    // 2--->5
    // 5--->6
    // 6--->7
    // 2--->8
    // 37
}