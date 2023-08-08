class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {

        vector<string> res;

        for (int i = 0; i < 26; ++i)
        {
            int counter = 101;
            char letter = 'a' + i;
            for (auto word : words)
            {
                int currCount = count(word.begin(), word.end(), letter);
                if (currCount < counter)
                {
                    counter = currCount;
                }
            }
            if (counter > 0)
            {
                for (int j = 0; j < counter; ++j)
                    res.push_back(string(1, letter));
            }
        }
        return res;
    }
};