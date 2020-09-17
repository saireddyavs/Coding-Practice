/*
 * Created on Thu Sep 17 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int minCoinsRequired(vector<int> coins, int number)
{

    vector<int> coins_required(number + 1, INT_MAX);

    coins_required[0] = 0;

    for (auto coin : coins)
    {
        for (int i = 0; i <= number; ++i)
        {
            if (i >= coin)
            {
                coins_required[i] = min(coins_required[i], 1 + coins_required[i - coin]);
            }
        }
    }

    // for(auto i:coins_required){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return coins_required[number];
}

int main()
{

    cout << minCoinsRequired(vector<int>{1, 2, 4}, 3) << endl;

    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 100) << endl;
    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 99) << endl;
    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 54) << endl;
    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 10) << endl;
    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 20) << endl;
    cout << minCoinsRequired(vector<int>{1, 2, 4, 5, 6, 10}, 11) << endl;
    return 0;

    // 2
    // 10
    // 11
    // 6
    // 1
    // 2
    // 2
}