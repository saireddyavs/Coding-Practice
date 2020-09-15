
/*
 * Created on Mon Sep 14 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words)
{
    unordered_map<string, vector<string>> m;
    string word_copy;
    for (auto word : words)
    {
        word_copy = word;
        sort(word_copy.begin(), word_copy.end());

        m[word_copy].push_back(word);
        // cout<<word_copy<<" "<<word<<endl;
    }

    vector<vector<string>> res;
    for (auto key_value : m)
    {
        res.push_back(key_value.second);
        // cout<<key_value.first<<endl;
    }
    return res;
}

int main()
{
    vector<string> words;
    vector<vector<string>> res;
    words = {"abc", "dabd", "bca", "cab", "ddba"};

    res = groupAnagrams(words);

    for (auto vec : res)
    {

        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    words = {"cinema", "a", "flop", "iceman", "meacyne", "lofp", "olfp"};

    res = groupAnagrams(words);

    for (auto vec : res)
    {

        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}