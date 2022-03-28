/*
 * Created on Mon Mar 28 2022
 *
 * Copyright (c) 2022 Sai Reddy
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size=nums.size();
        vector<int> result(nums.size());
        int start=0;
        int end=size-1;
        int position=end;
        while(start<=end){
            if(abs(nums[start])<abs(nums[end])){
                result[position]=nums[end]*nums[end];
                --end;
            }else{
                result[position]=nums[start]*nums[start];
                ++start;
            }
            --position;
        }
        return result;
    }
};