/*
 * Created on Mon Oct 12 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

void calculateLPS(string pattern, int lps[])
{
    int length_of_longest = 0;
    int j = 1;
    lps[length_of_longest] = 0;

    while (j < pattern.size())
    {
        if (pattern[j] == pattern[length_of_longest])
        {
            ++length_of_longest;
            lps[j] = length_of_longest;
            ++j;
        }
        else
        {
            if (length_of_longest != 0)
            {
                length_of_longest = lps[length_of_longest - 1];
            }
            else
            {
                length_of_longest = 0;
                lps[j] = 0;
                ++j;
            }
        }
    }
}

void kmp(string text, string pattern)
{
    int lps[pattern.size()];

    calculateLPS(pattern, lps);

    //  for(auto i:lps)cout<<i<<" ";
    cout << endl;
    int i = 0;
    int j = 0;
    while (i < text.size())
    {
        /* code */
        if (text[i] == pattern[j])
        {
            // cout<<i<<":::"<<j<<endl;
            ++j;
            ++i;
            if (j == pattern.size())
            {
                cout << "pattern start at-->" << i - pattern.size() << endl;
                // j=lps[j-1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                ++i;
            }
        }
    }
}

int main()
{

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    kmp(text, pattern);

    kmp("xyztrwqxyzfg", "xyz");

// pattern start at-->10

// pattern start at-->0
// pattern start at-->7
}