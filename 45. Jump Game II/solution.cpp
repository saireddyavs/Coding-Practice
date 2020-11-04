/*
 * Created on Wed Nov 04 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int jumps_done = 1;
        int remaing_steps = nums[0];
        int max_up_to_now = nums[0];

        for (int i = 1; i < nums.size() - 1; ++i)
        {
            --remaing_steps;
            max_up_to_now = max(max_up_to_now, i + nums[i]);
            if (remaing_steps == 0)
            {
                ++jumps_done;
                remaing_steps = max_up_to_now - i;
            }
        }

        return jumps_done;
    }
};