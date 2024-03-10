class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {

            if (nums[start] == 0)
            {
                ++start;
                continue;
            }
            if (nums[end] == 0)
            {
                swap(nums[start], nums[end]);
            }
            --end;
        }

        start = 0;
        for (auto ele : nums)
        {
            if (ele != 0)
                break;
            ++start;
        }
        end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] == 1)
            {
                ++start;
                continue;
            }
            if (nums[end] == 1)
            {
                swap(nums[start], nums[end]);
            }
            --end;
        }
    }
};