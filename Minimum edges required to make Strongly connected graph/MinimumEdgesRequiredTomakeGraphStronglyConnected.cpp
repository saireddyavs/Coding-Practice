/*
 * Created on Mon Oct 12 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int source, int destination)
{
    adj[source].emplace_back(destination);
}

void dfs(vector<int> adj[], bool visited[], int indegree[], int outdegre[], int vertex)
{

    visited[vertex] = true;

    indegree[vertex] = 1;

    for (auto adjacent : adj[vertex])
    {
        if (visited[adjacent] == false)
        {
            outdegre[vertex] = 1;
            dfs(adj, visited, indegree, outdegre, adjacent);
        }
    }
}

int minEdgesRequired(vector<int> adj[], int vertices)
{

    int indegree[vertices + 1], outdegree[vertices + 1];
    bool visited[vertices + 1];

    fill(indegree, indegree + vertices + 1, 0);
    fill(outdegree, outdegree + vertices + 1, 0);
    fill(visited, visited + vertices + 1, false);

    for (int i = 1; i < vertices; ++i)
    {
        if (visited[i] == false)
        {
            dfs(adj, visited, indegree, outdegree, i);
        }
    }

    int total_indegree = 0, total_outdegreee = 0;

    for (int i = 1; i < vertices; ++i)
    {
        total_indegree += indegree[i];
        total_outdegreee += outdegree[i];
    }

    cout << total_indegree << "---" << total_outdegreee << endl;

    int result = max(vertices - total_indegree, vertices - total_outdegreee);

    //for SCG all nodes should have atleat 1 in and out

    // (vertices-total_indegree) number of node's didnt have indegree and (vertices-total_outdegreee) number of nodes didnt have outdegree

    return result;
}

int main()
{

    int vertices = 6;

    vector<int> adj[vertices + 1];

    addEdge(adj, 1, 2);
    addEdge(adj, 3, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 5, 6);

    // for (auto i : adj)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    cout << minEdgesRequired(adj, vertices) << endl;
}
