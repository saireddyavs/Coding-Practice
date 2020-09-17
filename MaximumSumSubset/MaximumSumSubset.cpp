
/*
 * Created on Thu Sep 17 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

int maximumSumSubset(vector<int> arr){
    int one=arr[0];
    int two=max(arr[0],arr[1]);

    int maxi=two;

    for(int i=2;i<arr.size();i++){

        maxi=max(two,one+arr[i]);
        one=two;
        two=maxi;

    }   
    return two;
}



int main(){

    cout<<maximumSumSubset(vector<int>{10, 5, 20, 25, 15, 5, 5, 15, 3, 15, 5, 5, 15})<<endl;

    cout<<maximumSumSubset(vector<int>{7, 10, 12, 7, 9, 14, 15, 16, 25, 20, 4})<<endl;

// 90
// 72
    

}