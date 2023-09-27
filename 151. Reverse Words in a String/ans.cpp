class Solution
{

public:
    string reverseWords(string s)
    {

        istringstream ss(s);
        string word;
        vector<string> words;
        while (getline(ss, word, ' '))
        {

            if (word.length() == 0)
                continue;

            words.emplace_back(word);
        }
        string ans = "";
        for (int i = words.size() - 1; i > 0; --i)
        {
            ans += words[i];
            ans += " ";
        }
        ans += words[0];

        return ans;
    }
};