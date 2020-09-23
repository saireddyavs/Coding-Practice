/*
 * Created on Wed Sep 23 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    /* data */

    pair<bool, string> end_of_string;
    string word;
    unordered_map<char, Trie *> store;
};

Trie *newTrie()
{
    struct Trie *newtrie = new Trie();
    newtrie->end_of_string.first = false;
    newtrie->end_of_string.second = "";

    return newtrie;
}

void insert(struct Trie *root, string word)
{

    Trie *temp = root;

    for (auto i : word)
    {

        if (temp->store.find(i) == temp->store.end())
        {
            temp->store[i] = new Trie();
        }
        temp = temp->store[i];
    }

    temp->end_of_string.first = true;
    temp->end_of_string.second = word;
}

void checkPresence(vector<vector<char>> booggle_matrix, int i, int j, Trie *root, vector<string> &accepted, vector<vector<bool>> &visited)
{
    if (visited[i][j])
        return;

    char c = booggle_matrix[i][j];

    if (root->store.find(c) == root->store.end())
    {
        return;
    }
    visited[i][j] = true;
    root = root->store[c];
    if (root->end_of_string.first == true)
    {
        accepted.push_back(root->end_of_string.second);
        // cout<<root->end_of_string.second<<endl;
        // for(auto word:accepted)cout<<word<<endl;
    }

    vector<pair<int, int>> possible_neighbours = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}};

    for (auto neigh : possible_neighbours)
    {
        int index_i = i + neigh.first;
        int index_j = j + neigh.second;
        if (index_i >= 0 && index_j >= 0 && index_i < booggle_matrix.size() && index_j < booggle_matrix[0].size())
            checkPresence(booggle_matrix, index_i, index_j, root, accepted, visited);
    }

    visited[i][j] = false;

    // for(auto word:accepted)cout<<word<<endl;
}

vector<string> booggle(vector<vector<char>> booggle_matrix, vector<string> words)
{

    Trie *root = new Trie();

    for (auto word : words)
    {

        insert(root, word);
    }

    vector<string> accepted;

    vector<vector<bool>> visited(booggle_matrix.size(), vector<bool>(booggle_matrix[0].size(), false));

    //  cout<<"size:"<<accepted.size()<<endl;

    for (int i = 0; i < booggle_matrix.size(); ++i)
    {
        for (int j = 0; j < booggle_matrix[0].size(); ++j)
        {
            checkPresence(booggle_matrix, i, j, root, accepted, visited);
        }
        // for(auto word:accepted)cout<<word<<endl;
    }

    // cout<<"size:"<<accepted.size()<<endl;

    // for(auto word:accepted)cout<<word<<endl;

    return accepted;
}

int main()
{

    vector<vector<char>> booggle_matrix{

        {'G', 'U', 'Z'}, //U
        {'U', 'S', 'M'}, //S M
        {'Q', 'N', 'A'}, // A N
        {'G', 'Y', 'Z'}, //Y
        {'D', 'D', 'K'}, //D D
        {'Q', 'E', 'R'}, //R E
        {'G', 'I', 'Z'}, //I
        {'A', 'E', 'K'}, //A
        {'S', 'L', 'E'}, //S

    };

    vector<string> words{
        "SAIREDDY", "SASDFGT", "SUMAN", "SAI", "NANDARC"};

    vector<string> result = booggle(booggle_matrix, words);
    for (auto word : result)
        cout << word << endl;

    // SUMAN
    // SAI
    // SAIREDDY
    // SAIREDDY

    // SAIREDDY TWO times beacuse of DD

    return 0;
}
