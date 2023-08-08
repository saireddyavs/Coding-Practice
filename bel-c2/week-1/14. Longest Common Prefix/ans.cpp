class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string common = "";
        int start = 0;
        int end = strs.size() - 1;
        for (int i = 0; i < strs[start].size(); ++i)
        {
            if (strs[start][i] != strs[end][i])
                return common;
            common += strs[start][i];
        }
        return common;
    }
};