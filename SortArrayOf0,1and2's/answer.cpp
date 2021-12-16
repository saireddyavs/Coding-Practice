/*
 * Created on Thu Dec 16 2021
 *
 * Copyright (c) 2021 Sai Reddy
 */

#include <bits/stdc++.h>

using namespace std;

void sortZeroOneAndTwos(vector<int> &array)
{

    int end = array.size() - 1;
    int start = 0;
    int pointer = 0;

    while (pointer <= end)
    {

        if (array[pointer] == 0)
        {
            swap(array[pointer], array[start]);
            ++start;
            ++pointer;
        }
        else if (array[pointer] == 2)
        {
            swap(array[pointer], array[end]);
            --end;
        }
        else
        {
            ++pointer;
        }
    }
}

int main()
{

    vector<int> array;
    array = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0};
    sortZeroOneAndTwos(array);
    for (auto i : array)
    {
        cout << i << " ";
    }
    return 0;
}