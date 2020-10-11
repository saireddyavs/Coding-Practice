/*
 * Created on Sun Oct 11 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

//taking directed graph
void addEdge(vector<pair<int, int>> adj[], int source, int destination, int cost)
{
    adj[source].emplace_back(make_pair(destination, cost));
}

void Dijkstra(vector<pair<int, int>> adj[], int vertices, int source)
{
    bool visited[vertices] = {false};
    int distance[vertices];
    fill(distance, distance + vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});

    distance[source] = 0;

    while (!pq.empty())
    {
        pair<int, int> next = pq.top();
        pq.pop();

        int u = next.second;
        int w = next.first;

        for (auto v : adj[u])
        {
            if (visited[v.first] == false)
            {
                if (distance[v.first] > v.second + w)
                {
                    distance[v.first] = v.second + w;
                    pq.push({distance[v.first], v.first});
                }
            }
        }
    }

    replace(distance, distance + vertices, INT_MAX, 0);

    for (int i = 0; i < vertices; ++i)
    {
        cout << i << "--->" << distance[i] << endl;
    }
}

int main()
{
    int vertices = 9;
    vector<pair<int, int>> adj[vertices];

    // making above shown graph
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

    cout << "Source==0" << endl;
    Dijkstra(adj, vertices, 0);

    cout << "Source==1" << endl;
    Dijkstra(adj, vertices, 1);

    cout << "Source==2" << endl;
    Dijkstra(adj, vertices, 2);

    cout << "Source==3" << endl;
    Dijkstra(adj, vertices, 3);

    cout << "Source==4" << endl;
    Dijkstra(adj, vertices, 4);

    cout << "Source==5" << endl;
    Dijkstra(adj, vertices, 5);

    cout << "Source==6" << endl;
    Dijkstra(adj, vertices, 6);
    // Source==0
    // 0--->0
    // 1--->4
    // 2--->12
    // 3--->19
    // 4--->28
    // 5--->16
    // 6--->18
    // 7--->8
    // 8--->14
    // Source==1
    // 0--->0
    // 1--->0
    // 2--->8
    // 3--->15
    // 4--->24
    // 5--->12
    // 6--->14
    // 7--->11
    // 8--->10
    // Source==2
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->7
    // 4--->16
    // 5--->4
    // 6--->6
    // 7--->7
    // 8--->2
    // Source==3
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->0
    // 4--->9
    // 5--->14
    // 6--->16
    // 7--->17
    // 8--->22
    // Source==4
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->0
    // 4--->0
    // 5--->10
    // 6--->12
    // 7--->13
    // 8--->18
    // Source==5
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->0
    // 4--->0
    // 5--->0
    // 6--->2
    // 7--->3
    // 8--->8
    // Source==6
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->0
    // 4--->0
    // 5--->0
    // 6--->0
    // 7--->1
    // 8--->6
    //some are 0's because of directed graph
    return 0;
}