/*
 * Created on Sat Jan 30 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

bool check_border(int i, int j, int row_size, int col_size)
{
    return i == 0 or i == row_size - 1 or j == col_size - 1 or j == 0;
}

bool check_validity(int i, int j, int row_size, int col_size)
{
    return i < row_size && i >= 0 && j < col_size && j >= 0;
}

int getMinimumSteps(vector<vector<int>> grid)
{
    int row_size = grid.size();
    int col_size = grid[0].size();

    queue<pair<int, int>> reachable_positions;
    queue<pair<int, int>> firable_positions;

    pair<int, int> current;

    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            if (grid[i][j] == 1)
            {
                if (check_border(i, j, row_size, col_size))
                    return 0;
                else
                {
                    current = make_pair(i, j);
                }
            }
            else if (grid[i][j] == 2)
            {
                firable_positions.emplace(make_pair(i, j));
            }
        }
    }

    reachable_positions.emplace(current);
    int min_distace = 0;

    vector<pair<int, int>> adjacent_positions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}

    };

    vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));

    pair<int, int> prev;

    visited[current.first][current.second] = true;

    while (!reachable_positions.empty())
    {
        ++min_distace;
        for (int i = reachable_positions.size(); i > 0; --i)
        {
            current = reachable_positions.front();
            reachable_positions.pop();
            prev = current;

            if (grid[current.first][current.second] == 2)
                continue;

            for (auto adjacent : adjacent_positions)
            {
                current.first += adjacent.first;
                current.second += adjacent.second;

                if (check_validity(current.first, current.second, row_size, col_size))
                {
                    if (visited[current.first][current.second] or
                        grid[current.first][current.second] == 2)
                    {
                        //  do nothing
                    }
                    else if (check_border(current.first, current.second, row_size,
                                          col_size))
                    {
                        // cout << current.first << " " << current.second << endl;
                        // cout << prev.first << " " << prev.second << endl;

                        return min_distace;
                    }
                    else
                    {
                        reachable_positions.emplace(current);
                        visited[current.first][current.second] = true;
                    }
                }

                current = prev;
            }
        }

        for (int i = firable_positions.size(); i > 0; --i)
        {
            current = firable_positions.front();
            firable_positions.pop();
            prev = current;

            for (auto adjacent : adjacent_positions)
            {
                current.first += adjacent.first;
                current.second += adjacent.second;
                if (check_validity(current.first, current.second, row_size, col_size) &&
                    grid[current.first][current.second] != 2)
                {
                    grid[current.first][current.second] = 2;
                    firable_positions.emplace(current);
                }
                current = prev;
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0}, {2, 0, 0, 0}, {2, 1, 0, 0}, {2, 2, 0, 0}};

    cout << getMinimumSteps(grid) << endl;

    grid = {{0, 2, 0, 0}, {2, 1, 0, 2}, {2, 0, 0, 0}, {2, 0, 2, 0}};
    cout << getMinimumSteps(grid) << endl;
    return 0;
}
