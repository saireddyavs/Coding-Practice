class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> table(10, vector<int>(10, 0));
        for (int i = 0; i < 9; ++i)
        {
            vector<bool> rows(10, false);
            vector<bool> columns(10, false);
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (rows[num])
                        return false;
                    rows[num] = true;
                    int t = (i / 3) * 3 + (j / 3);
                    if (table[t][num])
                        return false;
                    table[t][num] = 1;
                }
                if (board[j][i] != '.')
                {
                    int num = board[j][i] - '0';
                    if (columns[num])
                        return false;
                    columns[num] = true;
                }
            }
        }
        return true;
    }
};