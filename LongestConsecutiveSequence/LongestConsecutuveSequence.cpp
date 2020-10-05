/*
 * Created on Mon Sep 28 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> longestConsecutiveSequence(vector<int> arr)
{

    unordered_map<int, bool> m;  

    for (auto i : arr)
        m.insert({i, false});

    int start = 0;
    int end = 0;

    int good_start = 0;
    int good_end = 0;

    int count = 0;
    int good_count = 0;

    for (auto i : arr)
    {
        if (!m[i])
        {
            m[i] = true;
            start = i - 1;
            end = i + 1;

            count = 1;

            while (m.find(start) != m.end())
            {
                /* code */
                m[start] = true;
                --start;
                ++count;
            }
            while (m.find(end) != m.end())
            {
                /* code */
                m[end] = true;
                ++end;
                ++count;
            }

            ++start;
            --end;

            if (count > good_count)
            {
                good_count = count;
                good_start = start;
                good_end = end;
            }
        }
    }

    return {good_start, good_end};
}

int main()
{

    pair<int, int> res;

    res = longestConsecutiveSequence(vector<int>{
        13, 1, 2, 7, 3, 8, 4, 9, 5, 10, 12, 34});

    cout << res.first << "->" << res.second << endl;

    res = longestConsecutiveSequence(vector<int>{
        1, -1, -2, 2, -3, 2, -4, 2, -5, 5, 0, -6});

    cout << res.first << "->" << res.second << endl;

    // 1->5
    // -6->2

    return 0;
}