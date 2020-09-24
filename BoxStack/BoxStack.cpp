/*
 * Created on Thu Sep 24 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct Box
{
    int Height, Length, Breadth;
    Box(int l, int b, int h)
    {
        Height = h;
        Length = l;
        Breadth = b;
    }
};

vector<Box> boxStack(vector<Box> boxes)
{

    sort(boxes.begin(), boxes.end(), [](Box l, Box r) {
        return l.Height < r.Height;
    });

    // for(auto box:boxes){
    //     cout<<box.Length<<":"<<box.Breadth<<":"<<box.Height<<endl;
    // }

    int max_height_upto_now[boxes.size()];

    int lower_disk_of_present_disk[boxes.size()];

    memset(lower_disk_of_present_disk, -1, sizeof(lower_disk_of_present_disk));

    max_height_upto_now[0] = boxes[0].Height;

    int max_height_index = 0;

    for (int i = 1; i < boxes.size(); ++i)
    {

        max_height_upto_now[i] = boxes[i].Height;

        for (int j = 0; j < i; ++j)
        {

            if (boxes[i].Height > boxes[j].Height && boxes[i].Breadth > boxes[j].Breadth && boxes[i].Length > boxes[j].Length)
            {

                if (boxes[i].Height + max_height_upto_now[j] > max_height_upto_now[i])
                {
                    max_height_upto_now[i] = boxes[i].Height + max_height_upto_now[j];
                    lower_disk_of_present_disk[i] = j;
                }
            }
        }

        if (max_height_upto_now[max_height_index] < max_height_upto_now[i])
        {
            max_height_index = i;
        }
    }

    vector<Box> result;

    int start = max_height_index;

    while (start != -1)
    {

        result.emplace_back(boxes[start]);
        start = lower_disk_of_present_disk[start];
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{

    vector<Box> boxes{
        Box(1, 2, 3),
        Box(4, 5, 6),
        Box(3, 9, 0),
        Box(6, 7, 8),
        Box(3, 2, 7),
        Box(1, 9, 8),
        Box(8, 9, 4)};

    vector<Box> result = boxStack(boxes);

    for (auto box : result)
    {
        cout << box.Length << ":" << box.Breadth << ":" << box.Height << endl;
    }

    // 1:2:3
    // 4:5:6
    // 6:7:8

    return 0;
}