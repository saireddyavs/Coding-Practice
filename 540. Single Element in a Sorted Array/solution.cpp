/*
 * Created on Thu Nov 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];

        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }

        return nums[nums.size() - 1];
    }
};