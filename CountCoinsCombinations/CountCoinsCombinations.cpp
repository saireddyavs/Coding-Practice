
/*
 * Created on Thu Sep 17 2020
 *
 * Copyright (c) 2020 SaiReddy
 */


#include<bits/stdc++.h>

using namespace std;

int numberofPossibleCombinations(vector<int> coins,int number){

    vector<int> result(number+1,0);

    result[0]=1;

    for(auto coin:coins){
        for(int i=coin;i<=number;++i){
            result[i]+=result[i-coin];

        }
    }

    // for(auto i:result){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return result.back();




}

int main(){

    cout<<numberofPossibleCombinations( vector<int>{1,2,3},4)<<endl;

    return 0;
}