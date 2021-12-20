
/*
 * Created on Mon Dec 20 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        if (rec1[3] <= rec2[1]  // goes out of top
            || rec1[2] <= rec2[0] // goes out of right
            || rec1[1] >= rec2[3] // goes out of bottom
            || rec1[0] >= rec2[2]) // goes out of left
            return false;

        return true;
    }
};