#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/* Linked List Algorithm exercise questions. */

// Leetcode 206. Reverse Linked List.
// Time - O(N) | Space - O(1)
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


// Leetcode 21. Merge Two Sorted Lists.
// Time - O(M + N) were M is the size of list1 and N is the size of list2. We need to iterate M+N times to merge the nodes into a single list.
// Space - O(1)
Node<int>* mergeTwoLists(Node<int>* h1, Node<int>* h2) {
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


int main (int argc, char *argv[]) {
    
    unique_ptr<LinkedList<int>> myList { new LinkedList<int>(5) };
        // Add at tail.
    myList->append(6);
    myList->append(7);
    myList->append(8);
    myList->append(9);

        // Add at head.
    myList->prepend(3);
    myList->prepend(2);
    myList->prepend(1);

    // Test List output.
    myList->printList();
    cout << "Length of list: " << myList->getLength() << endl << endl;

    // Delete at head test.
    myList->deleteFront();
    myList->printList();
    cout << "Length of list after deleting head node: " << myList->getLength() << endl << endl;

    // Delete at tail test.
    myList->deleteTail();
    myList->printList();
    cout << "Length of list after deleting tail node: " << myList->getLength() << endl << endl;

    // Get Index.
    int getIndx {3};
    Node<int>* ptr = myList->get(getIndx);
    cout <<"Get Node value: " << ptr->val << " at index: " <<  getIndx << endl << endl;


    /* Linked List Algorithm Exercises. */

    // Reverse List.
    LinkedList<int> revList;
    revList.append(100);
    revList.append(200);
    revList.append(300);
    revList.append(400);
    revList.append(500);


    Node<int>* revFront = reverseList( revList.head() ); 
    cout << "***Reverse List output:\n";

    while(revFront) {
        cout << revFront->val << endl;
        revFront = revFront->next;
    }


    // Merge Two Sorted Lists.
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(4);

    LinkedList<int> list2;
    list2.append(1);
    list2.append(3);
    list2.append(4);

    Node<int>* mergedList = mergeTwoLists(list1.head(), list2.head());
    cout << "***Merge two List output:\n";
    while(mergedList) {
        cout << mergedList->val << endl;
        mergedList = mergedList->next;
    }


    return 0;
}