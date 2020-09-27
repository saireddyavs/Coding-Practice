/*
 * Created on Sun Sep 27 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;

    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};

pair<int, vector<Item>> getKnapsackMaxProfit(vector<Item> items, int bag_capacity)
{

    vector<vector<int>> dp(items.size() + 1, vector<int>(bag_capacity + 1, 0));

    int i = 1;

    for (auto item : items)
    {
        for (int j = 0; j <= bag_capacity; ++j)
        {
            if (j < item.weight)
            {

                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item.weight] + item.value);
        }

        ++i;
    }

    // for(auto line:dp){
    //     for(auto i:line)cout<<i<<" ";
    //     cout<<"\n";
    // }

    vector<Item> res;

    int maxi = dp[items.size()][bag_capacity];

    for (int i = items.size(); i > 0; --i)
    {
        // cout<<"hi::"<<bag_capacity<<endl;

        if (dp[i][bag_capacity] != dp[i - 1][bag_capacity])
        {

            bag_capacity -= items[i - 1].weight;
            res.emplace_back(items[i - 1]);
        }

        if (bag_capacity == 0)
        {
            break;
        }
    }

    // cout<<maxi<<endl;

    return {maxi, res};
    // return dp[items.size()][bag_capacity];
}

int main()
{

    vector<Item> items{

        Item(60, 10),
        Item(100, 20),
        Item(120, 30)

    };

    int bag_capacity = 50;

    pair<int, vector<Item>> result = getKnapsackMaxProfit(items, bag_capacity);
    cout << result.first << "-->";
    for (auto item : result.second)
    {
        cout << "[" << item.value << "," << item.weight << "] ";
    }

    cout << endl;

    // 220-->[120,30] [100,20]

    return 0;
}