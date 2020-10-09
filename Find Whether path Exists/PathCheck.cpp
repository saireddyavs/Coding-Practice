
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
}

bool BFS(vector<int> adj[], int source, int destination, int total_vertices)
{

    // cout<<adj->size()<<endl;

    vector<bool> visited(total_vertices, false);

    queue<int> que;

    que.push(source);
    visited[source] = true;

    while (!que.empty())
    {
        /* code */

        int vertex = que.front();
        que.pop();

        for (auto i : adj[vertex])
        {
            if (i == destination)
            {
                return true;
            }
            if (visited[i] == false)
            {
                visited[i] = true;
                que.push(i);
            }
        }
    }

    return false;
}

bool isPathExists(vector<vector<int>> arr)
{

    vector<int> adj[arr.size() * arr.size() + 1];

    int vertex = 1;

    int source, destination;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {

            // cout<<i<<";;"<<j<<endl;

            if (arr[i][j] != 0)
            {

                // cout<<"camein:::"<<vertex<<endl;

                if (i > 0)
                {
                    addEdge(adj, vertex, vertex - arr.size());

                    // cout<<"done-1"<<endl;
                }
                if (i < arr.size() - 1)
                {
                    addEdge(adj, vertex, vertex + arr.size());

                    // cout<<"done-2"<<endl;
                }
                if (j > 0)
                {
                    addEdge(adj, vertex, vertex - 1);

                    // cout<<"done-3"<<endl;
                }

                if (j < arr.size() - 1)
                {
                    addEdge(adj, vertex, vertex + 1);

                    // cout<<"done-4"<<endl;
                }
            }

            if (arr[i][j] == 1)
            {

                source = vertex;
            }

            if (arr[i][j] == 2)
            {

                destination = vertex;
            }

            ++vertex;
        }
    }

    // cout<<"here"<<endl;

    // for(auto i:adj){
    //     // cout<<i<<"---->";
    //     for(auto j:i)cout<<j<<" ";
    //     cout<<endl;
    // }

    int total_vertices = arr.size() * arr.size() + 1;

    return BFS(adj, source, destination, total_vertices);
}

int main()
{

    vector<vector<int>> arr;
    arr = {
        {0, 3, 0, 1},
        {3, 0, 3, 3},
        {2, 3, 3, 3},
        {0, 3, 3, 3}};

    cout << isPathExists(arr) << endl;

    arr = {
        {0, 3, 0, 1},
        {0, 0, 0, 0},
        {2, 3, 3, 3},
        {0, 3, 3, 3}};

    cout << isPathExists(arr) << endl;

    arr = {
        {2, 3, 3, 3},
        {0, 0, 0, 3},
        {0, 0, 0, 3},
        {1, 3, 3, 3}};

    cout << isPathExists(arr) << endl;

    arr = {
        {2, 3, 3, 3},
        {0, 0, 0, 3},
        {3, 3, 3, 3},
        {3, 0, 0, 0},
        {3, 3, 3, 3},
        {0, 0, 0, 3},
        {1, 3, 3, 3}};

    cout << isPathExists(arr) << endl;

    arr = {
        {2, 0, 3, 3},
        {0, 0, 0, 3},
        {3, 3, 3, 3},
        {3, 0, 0, 0},
        {3, 3, 3, 3},
        {0, 0, 0, 3},
        {1, 3, 3, 3}};

    cout << isPathExists(arr) << endl;

    // 1
    // 0
    // 1
    // 1
    // 0

    return 0;
}