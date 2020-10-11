/*
 * Created on Sun Oct 11 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct edge
{
    /* data */
    int source, destination, weight;

    edge(int u, int v, int w) : source(u), destination(v), weight(w) {}
};

int parent[1000];
int rnk[1000];

// void addEdge(vector<pair<int,int>> adj[],int u,int v,int cost){
//     adj[u].emplace_back({v,cost});
//     adj[v].emplace_back({u,cost});
// }

int find(int u)
{

    if (u != parent[u])
    {
        parent[u] = find(parent[u]);
    }

    return parent[u];
}

void merge(int u, int v)
{
    int x = find(u);
    int y = find(v);
    if (x == y)
        return;

    if (rnk[x] < rnk[y])
    {
        swap(x, y);
    }

    parent[y] = x;
    if (rnk[x] == rnk[y])
        rnk[x] += 1;
}

int krushkals(vector<edge> adj, int vertices)
{
    int required_edges = vertices - 1;

    if (required_edges >= adj.size())
    {
        return -1;
    }

    // for(auto i:adj)cout<<i.source<<"-->>"<<i.destination<<"=="<<i.weight<<endl;

    // cout<<"after"<<endl;

    sort(adj.begin(), adj.end(), [](edge left, edge right) {
        return left.weight < right.weight;
    });

    // for(auto i:adj)cout<<i.source<<"-->>"<<i.destination<<"=="<<i.weight<<endl;

    int u, v, w, x, y, cost = 0, count_completed = 0;

    for (auto i : adj)
    {
        u = i.source;
        v = i.destination;
        w = i.weight;
        x = find(u);
        y = find(v);
        if (x == y)
        {
            continue;
        }
        ++count_completed;
        cost += w;
        cout << u << "--->" << v << endl;
        merge(u, v);
        if (count_completed == required_edges)
        {
            return cost;
        }
    }

    return 0;
}

int main()
{

    int vertices = 9;

    for (int i = 0; i < 9; ++i)
    {
        parent[i] = i;
        rnk[i] = 0;
    }

    vector<edge> edges{
        edge(0, 1, 4),
        edge(0, 7, 8),
        edge(1, 2, 8),

        edge(1, 7, 11),
        edge(2, 3, 7),
        edge(2, 8, 2),
        edge(2, 5, 4),
        edge(3, 4, 9),
        edge(3, 5, 14),
        edge(4, 5, 10),
        edge(5, 6, 2),
        edge(6, 7, 1),
        edge(6, 8, 6),
        edge(7, 8, 7)};

    cout << krushkals(edges, vertices) << endl;

    // 6--->7
    // 2--->8
    // 5--->6
    // 0--->1
    // 2--->5
    // 2--->3
    // 0--->7
    // 3--->4
    // 37
}