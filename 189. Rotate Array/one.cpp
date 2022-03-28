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
        if(k==0)return;
        int arr[k];
        int pos=0;
        for(int i=size-1;i>=size-k;--i){
            arr[pos]=nums[i];
            ++pos;
        }
        
       
        for(int i=size-k-1;i>=0;--i){
            nums[i+k]=nums[i];
        }
        
        for(int i=k-1,j=0;i>=0;--i,++j){
            nums[j]=arr[i];
        }
        
    }
};
