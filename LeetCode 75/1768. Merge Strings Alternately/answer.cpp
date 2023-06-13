class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int firstLength = word1.length();
        int secondLength = word2.length();
        int minLength = min(firstLength, secondLength);
        string ans;
        for (int i = 0; i < minLength; ++i)
        {
            ans += word1[i];
            ans += word2[i];
        }

        for (int i = minLength; i < firstLength; ++i)
            ans += word1[i];
        for (int i = minLength; i < secondLength; ++i)
            ans += word2[i];
        return ans;
    }
};