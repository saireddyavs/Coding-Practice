class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;

        vector<string> vec(numRows, "");

        bool endReached = true;

        int current = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (current == 0 || current == numRows - 1)
            {
                endReached = !endReached;
            }
            vec[current] += s[i];
            if (endReached)
            {
                --current;
            }
            else
            {
                ++current;
            }
        }

        string result;
        for (int i = 0; i < numRows; ++i)
        {
            result += vec[i];
        }
        return result;
    }
};