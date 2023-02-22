#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

// Linked List Algorithm exercise questions.
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

    // Test List output
    myList->printList();
    cout << "Length of list: " << myList->getLength() << endl << endl;

    // // Delete at head test
    myList->deleteFront();
    myList->printList();
    cout << "Length of list after deleting head node: " << myList->getLength() << endl << endl;

    // Delete at tail test
    myList->deleteTail();
    myList->printList();
    cout << "Length of list after deleting tail node: " << myList->getLength() << endl << endl;

    // Get Index.
    int getIndx {3};
    Node<int>* ptr = myList->get(getIndx);
    cout <<"Get Node value: " << ptr->val << " at index: " <<  getIndx << endl << endl;


    /* Linked List Algorithm Exercise */
    LinkedList<int> revList;
    revList.append(100);
    revList.append(200);
    revList.append(300);
    revList.append(400);
    revList.append(500);


    Node<int>* revFront = reverseList( revList.head() ); // Reverse List
    cout << "Reverse List output:\n";

    while(revFront) {
        cout << revFront->val << endl;
        revFront = revFront->next;
    }

    return 0;
}