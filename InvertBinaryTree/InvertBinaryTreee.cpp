/*
 * Created on Tue Sep 15 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include<bits/stdc++.h>

using namespace std;


struct Node
{
    /* data */
    int data;
    struct Node *left,*right;

};

void inorder(Node *root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void invertBinaryTree(Node *root){
    if(!root)return;

    swap(root->left,root->right);

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

}

int main(){

    Node *root=nullptr;

    root=new Node();
    root->data=3;
    root->left=new Node();
    root->left->data=4;
    root->right=new Node();
    root->right->data=5;


    inorder(root);


    invertBinaryTree(root);

    cout<<"\n";

    inorder(root);



}