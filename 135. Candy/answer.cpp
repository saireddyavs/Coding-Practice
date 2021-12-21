/*
 * Created on Tue Dec 21 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;

        int right[ratings.size()];
        int left[ratings.size()];

        right[0] = 1;
        for (int i = 1;i < ratings.size();++i) {

            if (ratings[i] > ratings[i - 1]) {
                right[i] = right[i - 1] + 1;
            }
            else {
                right[i] = 1;
            }

        }
        left[ratings.size() - 1] = 1;
        for (int i = ratings.size() - 2;i >= 0;--i) {

            if (ratings[i] > ratings[i + 1]) {
                left[i] = left[i + 1] + 1;
            }
            else {
                left[i] = 1;
            }

        }
        for (int i = 0;i < ratings.size();++i) {
            result += max(right[i], left[i]);
        }
        return result;

    }
};