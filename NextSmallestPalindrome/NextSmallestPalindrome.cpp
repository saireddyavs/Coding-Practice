/*
 * Created on Sun Sep 20 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;
list<int> getnextPalindrome(list<int> digits)
{

    int ninescount = count(digits.begin(), digits.end(), 9);

    int size = digits.size();

    if (ninescount == size)
    {
        list<int> res;

        res.assign(size - 1, 0);
        res.emplace_back(1);
        res.emplace_front(1);

        return res;
    }

    vector<int> digs(digits.begin(), digits.end());

    int mid = size / 2;
    int start = mid - 1;
    int end = size % 2 ? mid + 1 : mid;

    bool isalreadypalindrome = false;
    bool leftisgreaterthanright = false;

    while (start >= 0 && digs[start] == digs[end])
    {
        /* code */
        --start;

        ++end;
    }

    if (start == -1)
    {
        isalreadypalindrome = true;
    }

    if (start >= 0 && digs[start] < digs[end])
    {
        leftisgreaterthanright = true;
    }

    while (start >= 0)
    {
        digs[end] = digs[start];
        ++end;

        --start;
    }

    if (isalreadypalindrome == true || leftisgreaterthanright == true)
    {

        int carry = 1;
        start = mid - 1;
        if (size % 2)
        {
            digs[mid] += 1;
            carry = digs[mid] / 10;
            digs[mid] %= 10;
        }

        end = size % 2 ? mid + 1 : mid;

        while (start >= 0)
        {
            /* code */

            digs[start] += carry;
            carry = digs[start] / 10;
            digs[start] %= 10;
            digs[end] = digs[start];
            --start;
            ++end;
        }
    }

    return list<int>(digs.begin(), digs.end());
}

int nextSmallestPalindrome(int number)
{

    list<int> digits;

    int r;
    while (number > 0)
    {
        /* code */

        r = number % 10;

        digits.emplace_front(r);

        number /= 10;
    }

    // digits.pop_back();

    // for(auto i:digits)cout<<i<<" ";
    // cout<<endl;

    list<int> result;
    result = getnextPalindrome(digits);

    number = 0;

    for (auto i = result.rbegin(); i != result.rend(); ++i)
    {
        number *= 10;
        number += *i;
    }

    return number;
}

int main()
{

    int number;

    number = 2436;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;

    number = 999999;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 2346;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 123321;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 671232145;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 628798;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 100001;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;
    number = 2436123;

    cout << number << "::" << nextSmallestPalindrome(number) << endl;

    // 2436::2442
    // 999999::1000001
    // 2346::2442
    // 123321::124421
    // 671232145::671232176
    // 628798::628826
    // 100001::101101
    // 2436123::2436342
}