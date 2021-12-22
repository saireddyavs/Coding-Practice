/*
 * Created on Wed Dec 22 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;


        int rowStart = 0;
        int rowEnd = matrix.size() - 1;

        int colStart = 0;
        int colEnd = matrix[0].size() - 1;

        int i;

        while (rowStart <= rowEnd && colStart <= colEnd) {

            for (i = colStart;i <= colEnd;++i) {
                result.push_back(matrix[rowStart][i]);
            }

            for (i = rowStart + 1;i <= rowEnd;++i)result.push_back(matrix[i][colEnd]);

            if (rowStart < rowEnd) {
                for (i = colEnd - 1;i >= colStart;--i) {
                    result.push_back(matrix[rowEnd][i]);
                }
            }


            if (colStart < colEnd) {
                for (i = rowEnd - 1;i >= rowStart + 1;--i) {
                    result.push_back(matrix[i][colStart]);
                }
            }

            ++colStart, ++rowStart, --rowEnd, --colEnd;
        }

        return result;

    }
};