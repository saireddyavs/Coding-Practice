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

    while (parent > 0 && arr[child] < arr[parent])
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

    int small_child = parent;

    if (left_child <= total_elements && arr[left_child] < arr[small_child])
    {
        small_child = left_child;
    }

    if (right_child <= total_elements && arr[right_child] < arr[small_child])
    {
        small_child = right_child;
    }

    if (small_child != parent && arr[small_child]<arr[parent])
    {
        swap(arr[small_child], arr[parent]);
        heapDown(small_child);
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

    if (parent > 0 && arr[parent] > arr[i])
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

    // 2 12
    // 1 12 2
    // 1 5 2 12
    // 1 5 2 12 7
    // 1 5 2 12 7 10
    // 1 5 2 12 7 10 15
    // 1 5 2 12 7 10 15 13
    // 1 5 2 9 7 10 15 13 12
    // 1 7 2 9 12 10 15 13
    // 2 7 10 9 12 13 15
    // 2 7 10 9 12 13
    // 7 9 10 13 12

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