class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int end = nums.size() - 2;
        int steps_needed = 1;
        while (end > 0)
        {
            if (nums[end] >= steps_needed)
            {
                steps_needed = 1;
            }
            else
            {
                ++steps_needed;
            }
            --end;
        }
        if (nums[0] >= steps_needed)
            return true;
        return false;
    }
};