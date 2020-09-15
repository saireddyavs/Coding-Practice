/*
 * Created on Tue Sep 15 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

int maximumSumSubArray(vector<int> v){

    int result=v[0];

    int high=v[0];
    for(int i=1;i<v.size();i++){
        high=max(v[i]+high,v[i]);
        result=max(result,high);
        // cout<<result<<" "<<high<<endl;
    }
    return result;
}

int main(){

    vector<int> v{3, 4, -6, 7, 8};
    cout<<maximumSumSubArray(v);

}