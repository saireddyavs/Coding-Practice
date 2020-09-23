/*
 * Created on Wed Sep 23 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool validateBST(Node *root, int mini, int maxi)
{

    if (!root)
        return true;

    if (root->data < mini || root->data > maxi)
    {
        return false;
    }

    return validateBST(root->left, mini, root->data - 1) && validateBST(root->right, root->data + 1, maxi);
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

    struct Node *root;
    bool result;

    root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    result = validateBST(root, INT_MIN, INT_MAX);
    if (result)
    {
        cout << "IT is BST";
    }
    else
    {
        cout << "IT is not BST";
    }

    cout << "\n";

    root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    result = validateBST(root, INT_MIN, INT_MAX);
    if (result)
    {
        cout << "IT is BST";
    }
    else
    {
        cout << "IT is not BST";
    }

    // IT is not BST
    // IT is BST

    return 0;
}