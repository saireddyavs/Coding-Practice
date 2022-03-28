/*
 * Created on Mon Mar 28 2022
 *
 * Copyright (c) 2022 Sai Reddy
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;
        int lastIndex=size-1;
        // for(auto i:nums){cout<<i<<" ";}
        // cout<<endl;
        reverse(nums,0,lastIndex);
        //     for(auto i:nums){cout<<i<<" ";}
        // cout<<endl;
        reverse(nums,0,k-1);
        //     for(auto i:nums){cout<<i<<" ";}
        // cout<<endl;
        reverse(nums,k,lastIndex);
        //     for(auto i:nums){cout<<i<<" ";}
        // cout<<endl;
        
    }
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[end],nums[start]);
            --end;
            ++start;
        }
    }
};