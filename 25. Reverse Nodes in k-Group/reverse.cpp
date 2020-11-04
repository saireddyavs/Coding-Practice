/*
 * Created on Mon Oct 19 2020
 *
 * Copyright (c) 2020 SaiReddy
 */


// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == nullptr)
            return head;

        int length = 1;

        ListNode *temp = head, *prev = NULL, *curr = head, *next = head, *startNode = head, *result, *currNode;
        while (temp->next)
            temp = temp->next, ++length;

        int segments = length / k;

        int count = k;

        if (segments == 0)
            return head;

        while (count--)
        {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        result = prev;

        // cout<<segments<<endl;

        for (int i = 1; i < segments; ++i)
        {

            prev = NULL;
            currNode = curr;

            count = k;

            while (count--)
            {

                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // cout<<startNode->val<<" "<<prev->val<<endl;

            startNode->next = prev;
            startNode = currNode;
        }

        startNode->next = curr;
        return result;
    }
};