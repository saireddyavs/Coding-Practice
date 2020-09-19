/*
 * Created on Sat Sep 19 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void insert(int data,struct Node *head){

    struct Node *current = head;

    while (current->next!=NULL)
    {
        /* code */
        current=current->next;
    }

    struct Node *newnode= new Node();
    newnode->data=data;
    newnode->next=NULL;
    current->next=newnode;
    



}

void display(struct Node *head){
    struct Node *temp=head;
    while (temp!= NULL)
    {
       
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

void removeKthNodefromEnd(int position,struct Node *head){
    struct Node* pointer_one = head;
    struct Node* pointer_two= head;

    int pos=0;

    while (pos<position)
    {
        /* code */
        pointer_one=pointer_one->next;
        ++pos;
    }
    if(pointer_one==NULL){
        head->data=head->next->data;
        head->next=head->next->next;
    }
    else{
        while (pointer_one->next!=NULL)
        {
            /* code */
            pointer_one=pointer_one->next;
            pointer_two=pointer_two->next;
        }

        pointer_two->next=pointer_two->next->next;
        
    }
    

}

int main(){

    Node *head=new Node();
    head->data=1;
    head->next=NULL;

    insert(2,head);
    insert(3,head);
    insert(4,head);
    insert(5,head);
    insert(6,head);
    insert(7,head);
    insert(8,head);
    insert(9,head);
    insert(10,head);
    
    display(head);
    removeKthNodefromEnd(10,head);
    display(head);
     removeKthNodefromEnd(1,head);
    display(head);
     removeKthNodefromEnd(3,head);
    display(head);
     removeKthNodefromEnd(5,head);
    display(head);
// 1 2 3 4 5 6 7 8 9 10 
// 2 3 4 5 6 7 8 9 10
// 2 3 4 5 6 7 8 9 
// 2 3 4 5 6 8 9 
// 2 3 5 6 8 9 

    return 0;
}

