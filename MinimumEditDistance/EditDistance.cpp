/*
 * Created on Wed Sep 16 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

int minimumEditDistance(string str1,string str2){

    int arr[str1.length()+1][str2.length()+1];

    arr[0][0]=0;

    for(int i=1;i<=str1.length();i++){
        arr[i][0]=i;
    }

    for(int j=1;j<=str2.length();j++){
        arr[0][j]=j;
    }

    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){

            if(str1[i-1]==str2[j-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=1+min({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]});

            }
        }
    }

    return arr[str1.length()][str2.length()];


}

int main(){


    cout<<minimumEditDistance("abbbbbbbbb", "bbbbbbbbba")<<endl;



    cout<<minimumEditDistance("saireddy","suman")<<endl;

    cout<<minimumEditDistance("RGUKT","RGUKT-Basar")<<endl;


    cout<<minimumEditDistance("nandarc", "saireddy")<<endl;


    return 0;
}