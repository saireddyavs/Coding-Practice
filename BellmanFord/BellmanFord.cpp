/*
 * Created on Sun Oct 11 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

// edges are important so taking struct insted of array ..same like krushkals

struct edge
{

    int source, destination, weight;
    edge(int u, int v, int w) : source(u), destination(v), weight(w) {}
};

void bellmanFord(vector<edge> adj, int vertices, int edges, int source)
{

    int distance[vertices];
    fill(distance, distance + vertices, INT_MAX);

    distance[source] = 0;

    int u, v, w;

    for (int i = 0; i < vertices - 1; ++i)
    {
        for (int j = 0; j < edges; ++j)
        {
            edge edj = adj[j];
            u = edj.source;
            v = edj.destination;
            w = edj.weight;

            if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (int i = 0; i < edges; ++i)
    { //checking cycle
        edge edj = adj[i];
        u = edj.source;
        v = edj.destination;
        w = edj.weight;

        if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
        {
            printf("Graph has negative weight cycle");
            return;
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

    int vertices;
    vertices = 9;
    int edges;
    edges = 14;

    vector<edge> adj;
    adj = {

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
        edge(7, 8, 7)

    };
    cout << "Source==0" << endl;
    bellmanFord(adj, vertices, edges, 0);

    vertices = 5;
    edges = 8;
    adj = {
        edge(0, 1, -1),
        edge(0, 2, 4),
        edge(1, 2, 3),
        edge(1, 3, 2),
        edge(1, 4, 2),
        edge(3, 2, 5),
        edge(3, 1, 1),
        edge(4, 3, -3)};
    cout << "Source==0" << endl;
    bellmanFord(adj, vertices, edges, 0);

    cout << "Source==1" << endl;
    bellmanFord(adj, vertices, edges, 1);

    cout << "Source==2" << endl;
    bellmanFord(adj, vertices, edges, 2);

    cout << "Source==3" << endl;
    bellmanFord(adj, vertices, edges, 3);

    cout << "Source==4" << endl;
    bellmanFord(adj, vertices, edges, 4);

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
    // Source==0
    // 0--->0
    // 1--->-1
    // 2--->2
    // 3--->-2
    // 4--->1
    // Source==1
    // 0--->0
    // 1--->0
    // 2--->3
    // 3--->-1
    // 4--->2
    // Source==2
    // 0--->0
    // 1--->0
    // 2--->0
    // 3--->0
    // 4--->0
    // Source==3
    // 0--->0
    // 1--->1
    // 2--->4
    // 3--->0
    // 4--->3
    // Source==4
    // 0--->0
    // 1--->-2
    // 2--->1
    // 3--->-3
    // 4--->0

    return 0;
}
