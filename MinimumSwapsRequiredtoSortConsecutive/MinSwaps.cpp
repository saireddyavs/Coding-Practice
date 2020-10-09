/*
 * Created on Fri Oct 09 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int minSwaps(vector<int> arr)
{
    unordered_map<int, int> m;
    for (int i = 1; i <= arr.size(); ++i)
    {
        m[i] = arr[i - 1];
    }

    int result = 0;

    int next;

    vector<int> visited(arr.size() + 1, false);

    for (int i = 1; i <= m.size(); ++i)
    {

        if (visited[i] == false)
        {

            visited[i] = true;

            if (m[i] == i)
                continue;
            next = m[i];

            while (!visited[next])
            {

                visited[next] = true;

                next = m[next];

                ++result;
            }
        }
    }
    return result;
}
int main()
{

    cout << minSwaps(vector<int>{4, 3, 2, 1}) << endl;

    cout << minSwaps(vector<int>{1, 5, 4, 3, 2}) << endl;
    // 2
    // 2
    return 0;
}