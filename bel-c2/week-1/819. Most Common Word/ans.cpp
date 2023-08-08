bool isPunct(char c) { return (isPunct(c)); }
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        replace_if(
            paragraph.begin(), paragraph.end(), [](const char &c)
            { return std::ispunct(c); },
            ' ');
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        string result = "";
        string str = "";
        unordered_map<string, int> counter;
        unordered_set<string> bannedSet(banned.begin(), banned.end());

        stringstream ss(paragraph);

        while (ss >> str)
        {
            if (bannedSet.count(str) == 0)
            {
                ++counter[str];
                if (counter[result] < counter[str])
                {
                    result = str;
                }
            }
        }

        return result;
    }
};