class Solution
{
    vector<vector<string>> result;
    unordered_map<string, unordered_set<string>> adj;

public:
    void dfs(string start, string end, vector<string> &path)
    {
        path.emplace_back(start);
        if (start == end)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }
        for (auto i : adj[start])
        {
            dfs(i, end, path);
        }

        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return result;

        unordered_map<string, int> level;

        for (auto i : wordList)
            level[i] = -1;

        queue<string> que;

        level[beginWord] = 0;

        int word_size = beginWord.size();

        que.push(beginWord);

        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                string temp = que.front();
                que.pop();
                string original = temp;
                for (int i = 0; i < word_size; ++i)
                {
                    char original_char = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {

                        if (temp[i] == c)
                            continue;

                        temp[i] = c;

                        if (level.find(temp) == level.end())
                            continue;

                        if (level[temp] == -1)
                        {
                            level[temp] = level[original] + 1;
                            adj[original].insert(temp);
                            que.push(temp);
                        }
                        else if (level[temp] == level[original] + 1)
                        {
                            adj[original].insert(temp);
                        }
                    }
                    temp[i] = original_char;
                }
            }
        }

        vector<string> current_path;

        dfs(beginWord, endWord, current_path);

        return result;
    }
};