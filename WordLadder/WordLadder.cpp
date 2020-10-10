/*
 * Created on Sat Oct 10 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int wordLadderLength(string start, string target, vector<string> dict)
{

    unordered_map<string, bool> m;
    for (auto i : dict)
    {
        m[i] = false;
    }

    queue<string> que;

    que.push(start);

    if (m.find(target) == m.end())
        return 0;

    int result = 1;

    int flag = 1;

    while (!que.empty())
    {

        ++result;
        int que_size = que.size(); //for more than one possible toon--->poon,soon,coom,moon etc
        // cout<<endl;
        for (int k = 0; k < que_size; ++k)
        {

            string word = que.front();
            que.pop();
            // cout<<word<<" ";

            for (int i = 0; i < word.size(); ++i)
            {
                char original_char = word[i];
                for (int j = 0; j < 26; ++j)
                {

                    word[i] = 'a' + j;

                    if (m.find(word) != m.end() && m[word] == false)
                    {
                        if (word == target)
                            return result;

                        m[word] = true;

                        que.push(word);

                        flag = 0;
                    }
                }
                word[i] = original_char;
            }
        }

        if (flag)
            return 0;
    }

    return 0;
}

int main()
{

    string start;
    string target;
    vector<string> dict;

    start = "toon";
    target = "plea";
    dict = {
        "poon",
        "plee",
        "same",
        "poie",
        "plea",
        "plie",
        "poin"};

    cout << wordLadderLength(start, target, dict) << endl;

    cout << wordLadderLength(start, "plee", dict) << endl;

    cout << wordLadderLength(start, "plan", dict) << endl;
    // 7
    // 6
    // 0
    return 0;
}