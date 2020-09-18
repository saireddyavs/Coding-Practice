/*
 * Created on Fri Sep 18 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

void moveAllOccurancesToEnd(vector<int> &arr,int number){

 


    int start=0;
    int end=arr.size()-1;
    while(end>start){
        while (arr[end]==number)
        {
            /* code */
            --end;
        }

        if(end<start)break;

        if(arr[start]==number){
            swap(arr[start],arr[end]);
            

        }
  

        ++start;



        
    }

    

    return;
}

int main(){

    vector<int> v{1,2,3,1,4,1,3,4,2,4,5,6,2,3,1};

    int number=1;

    moveAllOccurancesToEnd(v,number);

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}