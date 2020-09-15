/*
 * Created on Sun Sep 13 2020
 *
 * Copyright (c) 2020 SaiReddy
 */


#include <bits/stdc++.h>

using namespace std;

struct Node
{

    int data;
    Node *left, *right;
};

Node *insert(Node *root, int number)
{
    Node **current = &root;
    while (*current)
    {
        if (number > (*current)->data)
        {
            current = &(*current)->right;
        }
        else
        {
            current = &(*current)->left;
        }
    }

    Node *temp = new Node;
    temp->data = number;
    temp->left = temp->right = nullptr;
    *current = temp;

    return root;
}

int search(Node *root, int number)
{
    Node *current = root;
    while (current)
    {
        cout << current->data << endl;
        if (current->data == number)
        {
            cout << "Found" << endl;
            return 0;
        }
        else if (current->data < number)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    cout << "Not Found\n";

    return 0;
}

int remove_node(Node *root, int number)
{
    Node **current = &root;
    Node **parent = nullptr;

    int f = 1;

    while (*current)
    {

        if ((*current)->data == number)
        {

            f = 0;
            break;
        }
        else if ((*current)->data > number)
        {
            parent = &(*current);
            current = &(*current)->left;
        }
        else
        {
            parent = &(*current);
            current = &(*current)->right;
        }
    }

    if (f == 1)
    {
        cout << "Not Found" << endl;
        return 0;
    }

    if ((*current)->left == nullptr && (*current)->right == nullptr)
    {
        *current = nullptr;
    }
    else if ((*current)->left && (*current)->right)
    {

        Node **temp = &(*current)->right;
        while ((*temp)->left != nullptr)
        {
            temp = &(*temp)->left;
        }

        (*current)->data = (*temp)->data;

        if ((*temp)->right == nullptr)
        {
            *temp = nullptr;
            return 0;
        }

        remove_node((*current)->right, (*temp)->data);
    }
    else
    {

        Node *child = (*current)->left ? (*current)->left : (*current)->right;

        *current = child;
    }
    return 0;
}

void inorder(Node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    Node *root = nullptr;

    while (1)
    {
        /* code */
        cout << "1.Insert 2.Search 3.Delete 4.Print\n";

        int choice, number;

        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */

            cout << "What do you want to insert:";
            cin >> number;
            cout << "\n";
            root = insert(root, number);
            break;
        case 2:

            cout << "Enter Number you want to search:";
            cin >> number;
            cout << "\n";

            search(root, number);
            break;

        case 3:
            cout << "Enter Number you want to delete:";
            cin >> number;
            cout << "\n";

            remove_node(root, number);
            break;
        case 4:

            inorder(root);
            cout << "\n";
            break;

        default:
            break;
        }
    }
}