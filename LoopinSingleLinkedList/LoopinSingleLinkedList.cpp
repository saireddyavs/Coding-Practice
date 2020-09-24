/*
 * Created on Thu Sep 24 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

int loopinSingleLinkedList(Node *head){

    set<int> s;
    Node *temp=head;
    while(s.find(temp->data)==s.end()){
        s.insert(temp->data);
        temp=temp->next;
    }

    return temp->data;


    return 0;
}

int main()
{

    Node *head=new Node(1);
    head->next=new Node(2);
    Node *loop_point=new Node(3);
    head->next->next=loop_point;
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=loop_point;

    cout<<loopinSingleLinkedList(head)<<endl;
    return 0;
}