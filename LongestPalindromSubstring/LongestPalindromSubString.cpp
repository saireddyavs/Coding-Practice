/*
 * Created on Wed Sep 16 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> checkpalindrome(string str, int first, int last)
{

    while (first >= 0 && last <= str.length())
    {
        /* code */
        if (str[first] != str[last])
        {
            break;
        }
        first -= 1;
        last += 1;
    }
    return {first + 1, last - 1};
}

string longesPalindromeSubstring(string str)
{

    pair<int, int> p, p1, p2;

    p.first = 0;
    p.second = 0;

    int diff1, diff2, diff;

    for (int i = 1; i < str.length(); i++)
    {

        p1 = checkpalindrome(str, i - 1, i + 1);
        p2 = checkpalindrome(str, i - 1, i);

        diff = p.second - p.first;
        diff1 = p1.second - p1.first;
        diff2 = p2.second - p2.first;

        p = diff > (max(diff1, diff2)) ? p : diff1 > diff2 ? p1 : p2;
    }

    return str.substr(p.first, p.second - p.first + 1);
}

int main()
{

    cout << longesPalindromeSubstring("abaxyzzyxf") << endl;

    cout << longesPalindromeSubstring("saiReddy") << endl;

    cout << longesPalindromeSubstring("SaiReddyddeRiasuman") << endl;

    // xyzzyx
    // dd
    // aiReddyddeRia
}