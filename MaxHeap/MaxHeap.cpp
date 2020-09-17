/*
 * Created on Thu Sep 17 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int total_elements = 0;

// doing 1 based indexing

void print()
{
    for (int i = 1; i <= total_elements; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapUp(int child)
{

    int parent = child / 2;

    while (parent > 0 && arr[child] > arr[parent])
    {
        swap(arr[parent], arr[child]);
        child = parent;
        parent = child / 2;
    }
}

void heapDown(int parent)
{

    int left_child = parent * 2;
    int right_child = parent * 2 + 1;

    int big_child = parent;

    if (left_child <= total_elements && arr[left_child] > arr[right_child])
    {
        big_child = left_child;
    }

    if (right_child <= total_elements && arr[right_child] > arr[big_child])
    {
        big_child = right_child;
    }
 
    // cout<<arr[big_child]<<"=>"<<arr[parent]<<endl;

    if (big_child != parent && arr[big_child]>arr[parent])
    {
        swap(arr[big_child], arr[parent]);
        heapDown(big_child);
    }
}

void insert(int element)
{

    arr[++total_elements] = element;
    heapUp(total_elements);
}

void remove(int element)
{

    int i;
    for (i = 1; i <= total_elements; ++i)
    {
        if (arr[i] == element)
        {
            break;
        }
    }

    // cout<<i<<":"<<arr[i]<<":"<<arr[total_elements]<<endl;

    arr[i] = arr[total_elements];
    total_elements -= 1;

    int parent = i / 2;

    if (parent > 0 && arr[parent] < arr[i])
    {
        heapUp(i);
    }
    else
    {
        heapDown(i);
    }
}

int main()
{

    int choice, number;

    insert(12);
    print();
    insert(2);
    print();
    insert(1);
    print();
    insert(5);
    print();
    insert(7);
    print();
    insert(10);
    print();
    insert(15);
    print();
    insert(13);
    print();
    insert(9);
    print();
    remove(5);
    print();
    remove(1);
    print();
    remove(15);
    print();
    remove(2);
    print();

// 12 2
// 12 2 1
// 12 5 1 2
// 12 7 1 2 5 
// 12 7 10 2 5 1 
// 15 7 12 2 5 1 10 
// 15 13 12 7 5 1 10 2 
// 15 13 12 9 5 1 10 2 7 
// 15 13 12 9 7 1 10 2 
// 15 13 12 9 7 2 10
// 13 10 12 9 7 2 
// 13 10 12 9 7 

    while (true)
    {
        /* code */

        printf("1.Insert 2.Remove 3.Print::");
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "\nEnter the number you want to insert::";
            cin >> number;
            insert(number);
            break;
        case 2:
            cout << "\nEnter the number you want to delete::";
            cin >> number;
            remove(number);
            break;
        case 3:
            print();
            break;
        default:
            cout << "\nInvalid" << endl;
            break;
        }
    }
}