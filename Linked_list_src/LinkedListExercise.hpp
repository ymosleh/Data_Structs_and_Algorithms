#include "LinkedList.hpp"
#pragma once

/*** Linked List exercise questions. ***/

/* 
    Leetcode 206. Reverse Linked List.
    Time - O(N) | Space - O(1) 
*/
Node<int>* reverseList(Node<int>* head) {
    Node<int>* current = head;
    Node<int>* prev =  nullptr;
    Node<int>* prev2 = nullptr;
    while (current) {

            // slide pointers
        prev2 = prev;
        prev = current;
        current = current->next;

            // Reverse Link
        prev->next = prev2;
    }
    head = prev;
    return head;
}


/* 
    Leetcode 21. Merge Two Sorted Lists.
    Time - O(M + N) were M is the size of list1 and N is the size of list2. We need to iterate M+N times to merge the nodes into a single list.
    Space - O(1) 
*/
Node<int>* mergeTwoSortedLists(Node<int>* h1, Node<int>* h2) {
    // Handle empty list cases.
    if (!h1 && !h2) return nullptr;
    else if (!h1) return h2;
    else if (!h2) return h1;

    Node<int>* m = nullptr; // Start of merged list.
    Node<int>* p = nullptr; // Prev pointer

    // Determine start of new list.
    if (h1->val <= h2->val) {
        m = p = h1;
        h1 = h1->next;

    } else  {
        m = p = h2;
        h2 = h2->next;
    }

    // Merge
    while (h1 && h2) {
        if (h1->val <= h2->val) {
            p->next = h1;
            p = h1;
            h1 = h1->next;

        } else {
            p->next = h2;
            p = h2;
            h2 = h2->next;
        }
    }

    // Need to check if we still have a list that we need to merge.
    if (h1) p->next = h1;
    else if (h2) p->next = h2;
    return m;
}

/*
 Leetcode 83. Remove Duplicate from sorted list.
 Time - O(N) | Space - O(1)
*/
void deleteDuplicateFromSortedLlist(Node<int>* h) {
    if (!h) return;
    Node<int>* cur = h->next;
    Node<int>* prev = h;

    while (cur) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            Node<int>* tmp {cur};
            cur = cur->next;
            delete tmp;

        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}



