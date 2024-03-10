class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        if (numRows >= 1)
        {
            result.emplace_back(vector<int>{1});
        }
        if (numRows >= 2)
        {
            result.emplace_back(vector<int>{1, 1});
        }
        if (numRows >= 3)
        {
            result.emplace_back(vector<int>{1, 2, 1});
        }
        if (numRows >= 4)
        {

            for (int i = 3; i < numRows; ++i)
            {
                vector<int> temp;
                temp.emplace_back(1);
                int to_build = (i + 1) - 2; // index=3 but row=4
                int half = (to_build + 1) / 2;

                for (int j = 1; j <= half; ++j)
                {
                    temp.emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
                }

                int other_half = (i + 1) - half - 2; // (i+1) i=3 row=2  and -2 because 1,1 are already there

                for (int j = other_half; j >= 1; --j)
                {

                    temp.emplace_back(temp[j]);
                }

                temp.emplace_back(1);
                result.emplace_back(temp);
            }
        }

        return result;
    }
};