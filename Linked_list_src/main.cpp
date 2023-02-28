#include "LinkedListExercise.hpp"
using namespace std;


void printListNode(Node<int>* p) {
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
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


    /*** Linked List Algorithm Exercises. ***/

    // Reverse List.
    LinkedList<int> revList;
    revList.append(100);
    revList.append(200);
    revList.append(300);
    revList.append(400);
    revList.append(500);


    Node<int>* revFront = reverseList( revList.head() ); 
    cout << "\n***Reverse List output:\n";
    printListNode(revFront);

    // Merge Two Sorted Lists.
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(4);

    LinkedList<int> list2;
    list2.append(1);
    list2.append(3);
    list2.append(4);

    Node<int>* mp = mergeTwoSortedLists(list1.head(), list2.head());
    cout << "\n***Merge two List output:\n"; 
    ptr = mp; 
    printListNode(ptr);

    deleteDuplicateFromSortedLlist(mp);
    cout << "\n***Duplicates removed, list output:\n";
    ptr = mp;
    printListNode(ptr);

    return 0;
}