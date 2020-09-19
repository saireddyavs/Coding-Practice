/*
 * Created on Sat Sep 19 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node *left, *right;
};

void verticalSumBinaryTree(struct Node *root, int position, map<int, int> &result)
{

    if (!root)
        return;

    // cout<<position<<endl;

    result[position] += root->data;

    verticalSumBinaryTree(root->left, position - 1, result);
    verticalSumBinaryTree(root->right, position + 1, result);
}

void display(struct Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

struct Node *createNode(int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right;
    return newNode;
}

int main()
{

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    map<int, int> result;

    verticalSumBinaryTree(root, 0, result);

    display(root);

    cout << endl;

    for (auto i : result)
    {
        cout << i.second << " ";
    }
    cout << endl;

    // 1 2 4 5 3 6 7
    // 4 2 12 3 7
}